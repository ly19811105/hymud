 inherit F_FOOD;
inherit ITEM; 
void create()
{
        set_name("Ģ��", ({ "mushroom" , "Ģ��"}) );
    set_weight(10);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "һ��������ź�ɫ�ߵ��Ģ���� \n");
        set("value", 1);
        set("food_remaining", 3);
                set("food_supply", 0);
                set("material", "food");         
    }
        
} 
int finish_eat()
{
        object me;
        
        me = this_player();
        me->apply_condition("mushroom", random(6));
}     