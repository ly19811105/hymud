// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit CLUB;

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
	set_name("[1;33m���֮��[2;37;0m", ({ "general club", "club" }));
	set_weight(11290);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
���֮��[2;37;0m����һ�����ޱȼ�Ӳ��[33m����[2;37;0m�Ƴɣ��ض�ʮ����������Ǯ��[1;33m���֮��[2;37;0m��
�ۺ�����[31m��������[2;37;0m �������ޱȷ���������[36m��С[2;37;0m��������
������˼����ŷ��ţ�
[1;35m��[2;37;0m:[31m����[2;37;0m 

���滹����һЩ���֣�
����:[32m�ֲ�[2;37;0m ��Դ:[32m����[2;37;0m 
��Ԩ:[33mһ��[2;37;0m 

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
		set("weapon_prop/karey",5);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",10);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",6);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "sword",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 3);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_club(108);
	setup();
}



#include "/obj/ritem/weaponzy.h";