// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit STAFF;

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

void create()
{
	set_name("[36m��ҩ֮��[2;37;0m", ({ "general staff", "staff" }));
	set_weight(13254);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
��ҩ֮��[2;37;0m����һ���ɷǳ���Ӳ��[33m����[2;37;0m�Ƴɣ��ض�ʮ����������Ǯ��[36m��ҩ֮��[2;37;0m��
�ۺ�����[31m��������[2;37;0m �������ǳ�����������[36m��С[2;37;0m��������
������˼����ŷ��ţ�
[31m��[2;37;0m:[35m��׼[2;37;0m [1;31mħ[2;37;0m:[34mϸ��[2;37;0m 
���滹����һЩ���֣�
����:[35m��׼[2;37;0m ����:[33mһ��[2;37;0m ����:[33mһ��[2;37;0m ����:[33mһ��[2;37;0m ����:[33mһ��[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 2000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 9);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 7);
    set("weapon_prop/jing", 8);
    set("weapon_prop/jingli", 8);
    set("weapon_prop/damage", 7);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",5);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",2);
    

                set("skill", ([
                        "name": "claw",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 5);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_staff(100);
	setup();
}



#include "/obj/ritem/weaponzy.h";