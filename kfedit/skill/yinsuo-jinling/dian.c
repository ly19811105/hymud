// dian.c �������� ��Ѩ
// By Kayin @ CuteRabbit Studio 1999/3/21 new
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	object ob;		
	string msg;
	int damage2;
int i;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��Ѩֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "whip")
			return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query_skill("yinsuo-jinling", 1) < 120 )
		return notify_fail("����������岻�����죬��������Ѩ\n");

	if( (int)me->query_skill("yunv-xinfa",1)< 135)
		return notify_fail("����ڹ���Ϊ̫������޷����Ѩ��\n");
	
	if( (int)me->query("max_neili")<1000)
		return notify_fail("�������������ʩչ��Ѩ����.\n");
			
	if ( (int)me->query("neili") < 300 )
		return notify_fail("�������������Ѩ��\n");
	me->add("neili", - 300);

	msg = CYN " $N"CYN"���Ͻ���"CYN"�ɳ�,ʹ������������ϳ˵�Ѩ����,ֱȡ$p"CYN"�Ĵ�׵Ѩ��\n";

	ob = target->query_temp("weapon");
	if( random( me->query("combat_exp") ) > random( target->query("combat_exp") )*2 )
	{
		me->start_busy(2);
		if (! objectp(ob))
		{
			int damage = 0;

			if (target->query_skill("dodge") > 200 && random(2) == 0)
			{
				switch (random(2))
				{
				case 0:
					msg += HIR " $p�������˼����ϳ�����������û�ܶ����"
						"$N�Ľ���������$p��̴��Ѩ�ϣ�$pֻ����һ��"
						"�������Ե�����ϣ���������˵���������ܡ�\n";
					damage = 3;
					break;
				case 1:
					msg += HIR " $p����Ʈ���������鶯֮����������Ҫ�Ȳʣ�"
              					"�����ۡ���һ��������ܸ$p��ɫɷ�ף�ҡҡ��׹��\n";
					damage = 5;
					break;
				}
			} else
			if (target->query_skill("force") > 200 && random(2) == 0)
			{
				switch(random(2))
				{
				case 0:
					msg += HIR " $p���һ�����Գ�������ǿ�����ֳ��У���࣡�"
						"��һ�����죬�����ཻ��$p����΢�Σ������ֽ��\n";
					damage = 3;
					break;
				case 1:
					msg += HIR " $pһ����Х��˫�ֻû���������Ӱ����ס��ǰ��"
						"ֻ�����͡���һ������Ӱ������$p�Ѿ������ɫ�Ұס�\n";
					damage = 4;
					break;
				}
			} else
			{
				switch(random(2))
				{
				case 0:
					msg += HIR " $p�������У���Ȼ��֪��ܣ����͡���һ����$N"
						"�Ľ���������$p�Ĵ�׵Ѩ��,$pȫ������,�����ڵء�\n";
damage2=(int)target->query("qi",1)/2;
if (damage2>50000) damage2=50000;
				target->receive_damage("qi", damage2/2,me);
                                target->receive_wound("qi", damage2/2,me);
//					target->unconcious();
					damage = 0;
					break;
				case 1:
					msg += HIR " $pһת��Ѿ�����˾�ʮ���ֻ���İ취��"
						"��δ���ü�ʩչ��ֻ�����͡���һ�����ѱ�$N���д�׵Ѩ,$pȫ������,�����ڵء�\n";
damage2=(int)target->query("qi",1)/2;
if (damage2>50000) damage2=50000;
				target->receive_damage("qi", damage2/3,me);
                                target->receive_wound("qi", damage2/3,me);

//					target->unconcious();
					damage = 0;
					break;
				}
			}
			if (damage > 0)
{
damage2=(int)target->query("qi",1)/2;
if (damage2>50000) damage2=50000;			
				target->receive_damage("qi", damage2/4,me);
                                target->receive_wound("qi", damage2/5,me);
			message_vision(msg + NOR, me, target);
}
			return 1;
		}

                if (!ob)
		return notify_fail("�㻹�����У����Է�û�б���������й��ò���\n");

		if (ob->query("item_make"))
		{
			msg += HIR " $pæ��" + ob->query("name") + "�мܣ�ֻ���û��ھ������ұ����������\n" NOR;
		} else
		{
if (ob)
{
if (!ob->query("systemmake") && !ob->query("ownmake"))
{
			msg += HIW " $p��æ�мܣ�ֻ������ž����һ����$p���е�" + ob->name()
				+ "�����ѣ�ɢ��һ�أ�\n";
			ob->unequip();
			ob->move(environment(target));
			ob->set("name", "�ϵ���" + ob->query("name"));
			ob->set("value", 0);
			ob->set("weapon_prop", 0);
}
}
		}
		target->start_busy(2);
	} else
	{
		int busy = 0;
		if (target->query_skill("dodge") > 200 && random(2) == 0)
		{
			switch (random(2))
			{
			case 0:
				msg += " $pһ����Ц�������仯�˼������������˶�Ŀ��һʱ��$N�޷�������\n";
				busy = 2;
				break;
			case 1:
				msg += " $pͻȻ���Ʈȥ���������磬��$N���еĺ�̱仯�޴�ʩչ��\n";
				busy = 1;
				break;
			}
		} else
		if (target->query_skill("force") > 200 && random(2) == 0)
		{
			switch (random(2))
			{
			case 0:
				msg += " $p��ɫ���أ��ӿ��ܣ����ɶ��ɣ���$N�޴����֣�ֻ���ջؽ��塣\n";
				busy = 3;
				break;
			case 1:
				msg += " $p������м����Цһ����˫�����������ޱȣ���$Nֻ�ܻ����Ծȡ�\n";
				busy = 1;
				break;
			}
		} else
		{
			switch (random(3))
			{
			case 0:
				msg += " $p��ҡ�һΣ�����ȥ�����·���ƫƫ�����$N��һ����\n";
				busy = 2;
				break;
			case 1:
				msg += " $p������������ȥ�鶯���$Nһ�������ƶٻ���\n";
				busy = 2;
				break;
			case 2:
                if (ob)
{
				msg += "$p��ס����������ע" + ob->query("name")
					 + "��������ס��$N�Ľ�����\n";
}
				busy = 2;
				break;
			}
		}
		target->start_busy(busy);

	}
	message_vision(msg + NOR, me, target);


if((int)me->query_skill("yinsuo-jinling",1) > 200)
 {
  me->add_temp("apply/attack", 80);
        me->add_temp("apply/damage", 1800);
        me->add("neili", - 100);
	for (i = 0; i < 7; i++)
	{
                if (! target->is_busy() && random(3) == 1)
                       target->start_busy(2);
 
         msg = HIC "һ��������У�$N�������"+(i+1)+"�ޣ�\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	}
        me->add_temp("apply/attack", -80);
        me->add_temp("apply/damage", -1800);
}        
		me->start_busy(3);
	return 1;
}