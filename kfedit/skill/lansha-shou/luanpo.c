// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����÷��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	 extra = me->query_skill("lansha-shou",1)/10;
   if ( extra < 5) return notify_fail("��ģ���ɰ�֣ݻ��������죡\n");
    if( (int)me->query("neili") < 600 )
    return notify_fail("�������������\n");
    if (me->query_skill("biyun-xinfa", 1) < 50 && me->query_skill("wudu-shengong", 1) < 50)
                return notify_fail("��ı����ڹ�ˮƽ���ޣ��޷���������Ķ�ɰ�ơ�\n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail( "ֻ�ܿ���ʩչ��\n");
	        if (extra> 200) extra=200;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", 500);
	msg = HIR  "$N˫��Ѫ�죬��ָ�������������Ʒ��ƿն�����������������Ѹ���ޱȵػ���$n��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIR  "$N��һ��������Ѹ���ޱȵ���$n�߳�����һ�ȣ�" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg = HIR "$Nʹ��ӥצ���еģ�ʮָ�����ݣ�˫�������������޵��������п���$n�Ĺؽ�Ҫ����\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
   msg = HIR"$N�����������������䣬Ѹ���ޱȣ�����Ȱ��۵�$n���ߣ���������������֣������ָ��ץ$n$l��\n"NOR ;
   COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
   msg = HIR"$Nһ�е��֣�������ͣ�����Ƽ������ָ����$n��ͷ��������ȥ��\n"NOR;
   COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -500);
	me->add("neili",-80);
	me->start_busy(2);
	return 1;
}