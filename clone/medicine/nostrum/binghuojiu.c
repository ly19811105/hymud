// /clone/medicine/nostrum/binghuojiu.c �����̻��
// Modified by Zeratul Jan 11 2001 force>�����ڹ�ʱ�Ⱦ�������������֮������

inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>

void init()
{
	add_action("do_drink", "drink");
	add_action("do_drink", "he");
}
void create()
{
	set_name(HIC "�����̻��" NOR, ({"xuanbingbihuo jiu", "jiu"}));
	set("unit", "��");
	set("long", "����һ�����֮���������̻��, ��˵��������Ϊ�м������档\n");
	set("value", 1000);
	set("lev", 1+random(3));
	set("pour_type", "1");
	setup();
}
int do_drink(string arg)
{
int exp,pot,i;
	object me = this_player();
	mapping	skill_map = me->query_skill_map();
	int force_limit = me->query_skill( "force" ) * 10;
	int neili_limit = me->query( "max_neili" );
	

exp = 888+random(888);
pot = exp/2;

	
	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), this_player()))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ȣ�С�ı�Ǻ���ˡ�\n");
if (me->query_condition("medicine"))
{message_vision("$N�ϴε�ҩ�Ի�û��", me);return notify_fail("���ϴε�ҩ�Ի�û����\n");}
	if(arg=="jiu")
	{
		tell_object(me, HIM"������ͷ���������еľƾ����ȸɣ���ʱ��ʹ��ʡ���������������\nҪ���������ź���֮�ﻯȥ����֪��ƵĶ��Է�ͬС�ɣ���һ����\n������ֻʹ����ȫ���鴤�����㾷�Σ���ʱ������ȥ��\n"NOR );

			if ( (int)me->query_condition("binghuo" ) > 0 )
			{
				tell_object(me, HIR"��źȴ˾�δ�ã���û���ڹ������������¾���ڣ�ʵ�ѵֵ���\n"NOR);
				me->add( "max_neili", -random(20) );
				me->unconcious();
			}
			else
			{
				tell_object(me, HIG"�㽫��ǰѧ��������������书ʩչ�������Ҵ����ġ�ֻ��ÿ����\nһȭһ�ƣ����е���ʹ�������������߶�����һЩ������ʹ��һ��\nȭ�ţ�������ʹҲ��֮������ֱ���綾��������Ǹ���Ҳ�Ͳ�����\nʹ��������Ϊ�ƺ����˲�С���档\n"NOR);
					me->add("max_neili", 50 + random(30) );
			}
       me->add("combat_exp",exp);me->apply_condition("medicine", 20);
       me->add("potential",pot);
message_vision("$N�����"+chinese_number(exp)+"�㾭��,"+chinese_number(pot)+"��Ǳ��!\n", me);
i=1+random(3);
if (random(12)==0 || wizardp(me))
{
if ( me->query("4zhuan") || me->query("5zhuan") )
{
if (me->query("expmax",1) < 1)
{
me->set("expmax",i);
}
else
{
me->add("expmax",i);
}       
message_vision(HIR"$N�����"+chinese_number(i)+"��ɳ�����!\n"NOR, me);
}       
}
		me->apply_condition("binghuo", 500);
		destruct(this_object());
	}
	return 1;
}