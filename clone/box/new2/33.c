// ���ں���������

#include <ansi.h>
inherit ITEM;
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}


int thunderspell(object me, object target)
{
	int	kee, damage, spells;
	string msg;
	int extra;
	int i;
	object weapon;
        int damagic;

        msg = RED"$N"RED"��ǹ����$n"HIR"����\n"NOR;
        msg += HIR"$n"HIR"���һ������������!!\n"NOR;
if (userp(target))
{
target->set("qi",target->query("max_qi")/3);
if (target->query("eff_qi") > target->query("max_qi")/2)
target->set("eff_qi",target->query("max_qi")/2);
target->set("neili",target->query("neili")/3);
}
else
{
target->add("qi",-10000);
target->add("eff_qi",-10000);
}
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);


if (target->query("qi") < 1)target->set("qi",0);
if (target->query("eff_qi") < 1)target->set("eff_qi",0);
if (target->query("max_qi") < 1)target->set("max_qi",0);                
if (target->query("jing") < 1)target->set("jing",0);
if (target->query("eff_jing") < 1)target->set("eff_jing",0);
if (target->query("max_jing") < 1)target->set("max_jing",0);                
if (target->query("neili") < 1)target->set("neili",1);
if (target->query("max_neili") < 1)target->set("max_neili",0);

	return 1;
	
}

void create()
{
        set_name(HIR"����������ǹ"NOR, ({ "helan huoqiang", "huoqiang" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ�ѿ���ʹ�õ���������ֻ��һ���ӵ�������ʹ��(use)\n") ;

                set("unit", "��");
                set("value", 150000);
                set("zhen", 3);
        }
        setup();
}

void init()
{
        add_action("do_shot","use");
}

int do_shot(string arg)
{
        object me,ob,target;
        int myskill , tgskill;
        int mylev ,damage;
        int damagic;
        string msg;
        object weapon;
	object	env;
	object	*inv;        
	int	i;
        me = this_player();

 	if (!id(arg))
	return notify_fail("���޷�ʹ�����!\n");
	
        if( !arg ) return notify_fail("�����˭ʹ�ã�\n");

      if( !target ) target = offensive_target(me);

      if( !target || !target->is_character() || !me->is_fighting(target) )
              return notify_fail("ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !target->is_character() || target->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");




if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("�Է�������С��û��Ҫʹ�ã�\n");
	
        if(me->is_busy() )
                return notify_fail("����æ���ġ�\n");


        if( !objectp(ob = present("helan huoqiang", me)) )
                return notify_fail("��û�����ֶ�����\n");

if (target->is_busy())
return notify_fail("���������ù������˵�ʱ�򰡣�\n");
                me->start_busy(3);
        message_vision(HIR"\n$N"HIR"ͻȻ����  ��ǹ���!!  \n"NOR,this_object(),target);

	env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( !inv[i]->is_fighting(me) ) continue;
                if( inv[i]==me ) continue;
	        if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
		thunderspell(me, inv[i]);
        }
 
        destruct(this_object());
        return 1;
}