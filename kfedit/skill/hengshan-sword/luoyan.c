// luoyan.c �ط�����
// Last Modified by ahda on Aug.31 2001

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

#define PNAME "���ط����㡹"

int perform(object me,object target)
{
	string msg;
	object weapon;
	int ap,dp,qi_wound;
	int flag,i,lmt;
	
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];


	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	fskill = "huiyan-xinfa";
	bskill = "sword";


	if( (int)me->query_skill(fskill, 1) < 80 )
		return notify_fail("���"+to_chinese(fskill)+"�ȼ�����, ����ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 80 )
		return notify_fail("���"+to_chinese(sskill)+"�ȼ�����, ����ʹ��"+PNAME+"��\n");

	if( me->query("neili") < 250 )
		return notify_fail("��������������޷�����"PNAME"��\n");

	msg = HIC"$N"HIC"һ����Х������������һʽ���ط����㡹��"+weapon->name()+HIC"�������磬˲����ס$n"HIC"ȫ��������Ѩ��\n��Ӱ�У�ֻ��$N΢һ���������ַ�ת��������"+weapon->name()+"ͻȻ���϶��´̳���ֱָ$n"HIC"����Ҫ�� \n" NOR;
	message_combatd(msg, me, target);

	ap = me->query("combat_exp");
	dp = target->query("combat_exp") / 3;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili",-200);
		msg = HIY"$n��ʱ������ǰ���������˫��������������֪����һ���ʹ������һ�㣡\n" NOR;
		qi_wound = 300+(int)me->query_skill(bskill,1) * 2;
		qi_wound = qi_wound/2 + random(qi_wound);

		target->receive_damage("qi", qi_wound,me);
		target->receive_wound("qi", qi_wound,me);
		target->start_busy(2);
		me->start_busy(random(3));
	}
	else
	{
		if(userp(me)) me->add("neili",-100);
		msg =HIW"����$n�����������ֽ�$N������Ʋ��һ�ߡ�\n"NOR;
		me->start_busy(random(3));
	}
	message_combatd(msg, me, target);


      msg = HIY  "$N��ɫ����,���н�â�ó���ʹ�â����������$n����Ȧȥ��\n\n" NOR;
        message_vision(msg,me,target);
        lmt = random(2)+3;
        		       me->add_temp("apply/attack", 90);    
        me->add_temp("apply/damage", 1500);
        for(i=1;i<=lmt;i++)
        {
        msg =  HIC "��"+chinese_number(i)+"Ȧ ��â��\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
		       me->add_temp("apply/attack", -90);    
        me->add_temp("apply/damage", -1500);


	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���˶Է���Ѫ

	����Ҫ��
		�����ķ�80��
		��ɽ����90��
		����250
HELP
	);
	return 1;
}
