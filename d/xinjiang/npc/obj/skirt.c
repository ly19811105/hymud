 //COPYRIGHT (C) APSTONE, INC. 1998
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("������˹ȹ", ({ "cotton skirt" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����Ư����ȹ�ӣ������ƺ����е�����������ζ��\n");
                set("value", 200);
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
         setup();
}  