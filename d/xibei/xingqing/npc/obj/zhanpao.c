#include <armor.h>
inherit SURCOAT;
void create()
{
    set_name("�ɺ�ս��", ({ "zhan pao", "cloth", }) );
    set_weight(500);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "���Ǿ�����ͨ�õľ�������־�������ݵ�ս�ۡ�\n");
        set("unit", "��");
        set("value",140);
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}
