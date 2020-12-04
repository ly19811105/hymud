// bing_poison.c
// Last Modified by winder on Feb. 28 2001

#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	tell_object(me,HIB"ͻȻ��о���֫������ƺ�������㣡\n"NOR);
	tell_room(environment(me),HIB+me->name()+"ͻȻȫ��һ����������������ȫ�ɺ�ɫ��������˳���ֱ�����������\n"NOR, ({ me }));     
	me->receive_damage("qi", 125);
	if(userp(me)) me->receive_wound("jing", 120);
	else me->receive_wound("jing", 140);
	if(!me->is_busy()) me->start_busy(2);

	me->apply_condition("bing_poison", duration - 1);
		if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}