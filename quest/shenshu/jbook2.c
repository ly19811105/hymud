#include <ansi.h>
inherit ITEM;
#include "/quest/givetaskgift.c"
void create()
{
    set_name(HIW"��ӹȫ���²�"NOR, ({ "jin bookb" }) );
            set("no_put", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("shenshu",1);
            set("unit", "��");
            set("no_put", 1);
            set("material", "paper");
            set("long", "һ��������ϲ��ɵľ��ᣬ�������(chayue)����������\n");
          }

    setup();
}
void init()
{
   add_action("do_cha","chayue");
}
int do_cha(string arg)
{
	object me,corpse;
	int exp,pot,score;
	me =this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	exp = 18800+random(8000);
	             pot = exp*2/3;
             score = random(200)+100;

     	      message_vision("$N��ϸ�ز�����һ��"+this_object()->query("name")+"��\n", me);
        addnl(me,"exp",exp);
        addnl(me,"score",score);
if (random(2)==0)
{
        corpse=new("/clone/gem/gem");
if (corpse->query("level") >4
&& random(2)>0)
{
        corpse=new("/clone/gem/gem");
}


message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "ͨ�����������ҵ���һ��"+corpse->query("name")+HIM"!"NOR"��\n", users());
             corpse->move(me);
}

	destruct(this_object());
return 1;
}