// qing.c ��˼��

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage, ap, dp;
	string msg;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("����˼����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query_skill("tianyu-qijian", 1) < 70)
		return notify_fail("��������潣������죬����ʹ�á�\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("����ڹ�ʵ��̫�û���á���˼������\n");

	if ((int)me->query("neili", 1) < 300)
		return notify_fail("����������̫��������ʹ�á���˼������\n");

        if (me->query_skill_mapped("sword") != "tianyu-qijian")
                return notify_fail("��û�м��������潣��û���á���˼������\n");

	msg = HIG "$N" HIG "��������һ�������е�" + weapon->name() +
	      HIG "����һ���ʺ磬�⻪ѣĿ��������$n" HIG "��\n" NOR;

        ap =  me->query_skill("sword");
        dp =  target->query_skill("dodge");
        
        if (ap / 2 + random(ap) > dp)
        {
                damage =  me->query_skill("sword");
                
		me->add("neili", -120);
  target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "ֻ��$N" HIR "������Ϊһ�ߣ�����$n"
                                           HIR "��$p" HIR "ֻ��һ���������Ķ�����"
                                           "��ͷһ����Ѫ���������\n" NOR;		

		me->start_busy(2);
	} else 
	{
		msg += CYN "����$p" CYN "�͵���ǰһԾ,������$P"
                       CYN "�Ĺ�����Χ��\n"NOR;
		me->add("neili", -100);
		me->start_busy(4);
	}
	message_combatd(msg, me, target);

	return 1;
}