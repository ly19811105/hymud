#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIG"��ò��"NOR, ({ "jobzhu6" }) );
    set_weight(1);
            set("no_put", 1);
            set("value", 0);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	       
            set("no_put", 1);
            set("no_steal", 1);
            set("no_get", 1);
            set("no_beg", 1);
            set("value", 0);
            set("unit", "��");
            set("material", "paper");
            set("long", "����֮һ��\n");
          }

    setup();
}
void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

  	me->add("combat_exp", 2000);
	me->add("potential",1000);        
	me->add("max_neili",50);
        message_vision(HIG "$N�԰��������ȥ��ֻ����ȫ������˲���!\n" NOR, me);
	
	destruct(this_object());
	return 1;
}