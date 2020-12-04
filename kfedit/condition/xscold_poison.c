#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int damage;
        if( !living(me) ) {
                message("vision",HIB + me->name() + "ɪɪ���������Ϻ�������,ȫ������һ�㱡���İ�˪����\n"NOR, environment(me), me);
        }
        else {

                tell_object(me, HIB "��Ȼһ�ɺ������Ʊ�����ѭ���ֱۣ�Ѹ�����׵��������ţ����е�ѩɽ���������ˣ�\n" NOR );
                message("vision", HIY + me->name() + "�˿ڴ��������� ���촽Ҳ���ˣ���ɫ����������ס�\n"NOR,
                                environment(me), me);

        }
        me->receive_damage("qi", 150);
        me->receive_wound("jing", 120);

damage = me->query("jing")/30;
if (damage > 20000) damage=20000;
        me->receive_wound("jing", damage);

damage = me->query("qi")/30;
if (damage > 20000) damage=20000;

        me->receive_wound("qi", me->query("qi")/20);

        me->start_busy(5);
        me->apply_condition("xscold_poison", duration - 1);
        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}