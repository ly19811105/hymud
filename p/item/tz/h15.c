// mdiamond.c ��֮��ʯ

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIW "��֮��ʯ" NOR, ({ "magic diamond" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIW "һ�Ż���������Ĺ�ʵ���ʯ��"
                    "�����Բ�ͬѰ���ĸо���\n" NOR);
                set("value", 12000);
		        set("unit", "��");set("no_get",1); set("no_put",1);set("no_pawn",1);set("no_drop",1);set("no_beg",1);set("no_steal",1);set("systemmake",1);
                set("can_be_enchased", 1);
                set("magic/type", "lighting");
                set("magic/power", 15 + random(16));
                set("armor_prop/percao", 18);
                set("armor_prop/karay",18);
set("armor_prop/armor", 170);

                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
	}
        setup();
}

