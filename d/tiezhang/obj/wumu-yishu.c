// wumu-yishu.c
// zqb

#include <ansi.h>

inherit ITEM;
void init()
{
        add_action("do_du", "dushu");
}

void create()
{
	set_name( "���������项", ({ "wumu yishu", "yishu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			GRN
			"\n���������������ǰ���µġ��ƽ�Ҫ������\n"
			"ֻ����һҳ��д��ʮ�˸����֣�\n"
                        "������ѡ����ѵϰ��\n"
                        "�����ͷ��������\n"
                        "���ϼ�  ��ͬ�ʿࡱ\n"
                        "�������(dushu)��\n"
               NOR
		);
		set("value", 10000);
		set("material", "paper");
//		set("no_get", 1);
//		set("no_drop", 1);
		set("treasure", 1);
	}
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        
if (!id(arg))
	return 0;

//if( me->query("wumu+int")) 
if ((int)this_player()->query("mark/+int")) 
        {
        write("�������һ����������ѽ�����Ѿ������ˣ���Ϊ�˲��ý��˻�����еı�������Ͱ�����ٵ��ˡ�\n");
        destruct(this_object());
        }
        else
        {
        me->add("int", 1);
        write(HIY"�����ַ��ģ�����һ��һ��֮�䣬�޲���������Եе��������������̾��\n"NOR);
        write(HIR"�����������ˣ�\n"NOR);
        write(HIY"�㿴����,Ϊ�˲��ý��˻�����еı������Ͱ�����ٵ��ˡ�\n"NOR);
        this_player()->set("mark/+int", 1); 
        destruct(this_object());
        }
        return 1;
}