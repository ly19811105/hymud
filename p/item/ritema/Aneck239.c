#include <ansi.h> 
#include <armor.h>

inherit NECK;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;31m��ˮ֮����[2;37;0m", ({ "good neck", "neck" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
��ˮ֮����[2;37;0m����һ�����ޱȼ�Ӳ�ľ��ּ���[33m����[2;37;0m�Ƴɣ�����������Ǯ��[1;31m��ˮ֮����[2;37;0m��
�ۺ�����[1;34m��������[2;37;0m �������ޱȼ�̣�����[36mһ��[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;34m����[2;37;0m [36mľ[2;37;0m:[31m����[2;37;0m [32mˮ[2;37;0m:[32m�ֲ�[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;31m��Ԫ[2;37;0m ����:[32m�ֲ�[2;37;0m 
����:[32m�ֲ�[2;37;0m ��ʯ:[32m�ֲ�[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 9000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 30);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 47);
    set("armor_prop/defense", 37);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",8);
    set("wtypeB",6);
    set("wtypeC",3);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "claw",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		


		set("material", "default");
    set("sharpness", 13);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";