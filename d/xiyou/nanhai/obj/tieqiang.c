//Cracked by Roath
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("��ǹ", ({"iron spear", "qiang", "spear"}));
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѳ�ǹ��ǹ���������⣮\n");
                set("value", 500);
                set("material", "iron");
                set("wield_msg","$N�ó�һ��$n���������У�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_staff(40);
        setup();
}
