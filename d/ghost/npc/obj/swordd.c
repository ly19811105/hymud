 // sword.c
#include <weapon.h> 
inherit SWORD; 
void create()
{
        set_name("��ľ��", ({ "sword" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��רΪ�䵱����ʹ�õı�����\n");
                set("value", 2000);
                set("material", "steel");
                set("rigidity", 80);
                set("wield_msg", "$N�ӽ����г��һ�����������$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        }
        ::init_sword(70);
}  