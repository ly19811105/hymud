//by dewbaby@sk_sjsh
//�Ž�������

#include <ansi.h>


inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i,j;
        int kwj;

        if( !target ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) 
        || !living(target))
           return notify_fail("�����Ρ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        kwj = me->query_skill("wuyun-jian");
        if( (int)me->query_skill("wuyun-jian", 1) < 120 )
                return notify_fail("������Ž����ȼ��������ٺú������ɡ�\n");

        if( (int)me->query_skill("sword", 1) < kwj )
                return notify_fail("��Ļ��������ȼ�����!\n");


            if( time()-(int)me->query_temp("meng_end") < 3 )    
                return notify_fail(WHT"[����]��������,�޷�����ʹ��!\n"NOR);    


        if ( !wizardp(me) && me->query_skill_mapped("force") != "wuzheng-xinfa")
                return notify_fail("��ʹ�������ķ�!\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
        if( (int)me->query("max_neili") < 1500 )
                return notify_fail("�������̫����!\n");
        if( (int)me->query("neili") < 500 )

                return notify_fail("�����������!\n");

        if (!objectp(weapon = me->query_temp("weapon"))
           || weapon->query("skill_type") != "sword"
           || me->query_skill_mapped("sword") != "wuyun-jian")
            return notify_fail("����������ʹ�������Ρ���\n");
        
        i = (int)me->query_skill("wuyun-jian",1)/2;
        j = (int)me->query("max_neili",1)/110*4+20;   
 if (i> 300) i=300;
        if (j> 3000) j=3000;
 
   message_vision(WHT"$N���б������㳯$n"WHT"������ȥ��һ�������������\n\n"HIC"$n"HIC"���Ƶýп�������ȴ�㲻���������εĽ���!\n"NOR,me,target);

        me->add_temp("apply/attack", i);
        me->add_temp("apply/dodge", i);
        me->add_temp("apply/damage", 800);
       me->add("neili", -90);

        target->start_busy(random(2));
        target->receive_damage("qi",(j+100),me);
        target->receive_wound("qi", (i+100),me);
        target->add("neili",-j);
   	   message_vision(WHT"$N������������������˭ͬ?˷�����ա�ѩӳ�Ļ��죬��ҹ��Ѭ������\n\n"HIC"$n"HIC"����һͷ��ˮ�������������������Σ��֮�У�\n"NOR,me,target);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);

                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);

                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  

        me->add_temp("apply/attack", -i);
        me->add_temp("apply/dodge", -i);
        me->add_temp("apply/damage", -800);


       me->start_busy(2);
       return 1;
}

