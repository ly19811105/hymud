 inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("̴ľ��", ({ "table","desk","̴ľ�輸","̴ľ��",}) );
        set_weight(500);
        set_max_encumbrance(8000000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���Ϻõ�̴ľ�輸����ɢ���ŵ�������ζ��\n");
                set("value", 1);
                set("prep", "on");
        }
        
} 
int is_container() { return 1; }       