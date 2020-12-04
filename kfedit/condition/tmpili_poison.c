#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   int damage;
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "ʹ��غ���һ����\n", environment(me), me);
   }
   else {
      tell_object(me, HIR "��Ȼһ������������Ϯ�������е����ŵ�������֮�������ˣ�\n" NOR );
      message("vision", me->name() + "������ͻȻ�������Σ�����һ��Ť��,�������ʹ�ࡣ\n",
            environment(me), me);
   }
      damage=me->query("qi")/15;
      if (damage > 25000) damage=25000;
      me->receive_wound("qi",damage);

      if (me->query("jing") >200)
      me->receive_wound("jing", 180);
      me->start_busy(2);
      if (me->query("neili") >200)
      me->add("neili",-150);
      me->apply_condition("tmpili_poison", duration - 1);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}