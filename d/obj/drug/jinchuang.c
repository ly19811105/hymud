// jinchuang.c ��ҩ
#include <ansi.h>

inherit COMBINED_ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("��ҩ", ({"jinchuang yao", "yao", "jinchuang"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
             set("base_unit","��");
        set("color",HIY);
        set("unit","Щ");
                set("long", "����һ�����˵Ľ�ҩ��\n");
set("value", 600);
				set("drug_type", "��ҩ");
        }
   set_amount(1);
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ��ʲôҩ��\n");
//        if ((int)this_player()->query("eff_qi") == 
//            (int)this_player()->query("max_qi"))
//                return notify_fail("�����ڲ���Ҫ�ý�ҩ��\n")
        else {
                this_player()->receive_curing("qi", 50);
                message_vision("$N����һ����ҩ����ɫ�������ö��ˡ�\n",
this_player());
         add_amount(-1);
                return 1;
        }
}
