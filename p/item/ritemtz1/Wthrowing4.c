// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit THROWING;

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
	set_name("[31m�ɽ�֮����[2;37;0m��", ({ "ganjiang throwing", "throwing" }));
	set_weight(636);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("long", @LONG
[31m�ɽ������ޱȣ��ܿ���ٵأ�������ħ��
[2;37;0m����һ֧���ޱȼ�Ӳ��[1;37m����[2;37;0m�Ƴɣ���һ�������Ǯ��[31m�ɽ�֮����[2;37;0m��
�ۺ�����[35m�������[2;37;0m �������ޱȷ���������[1;34m��������[2;37;0m��������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;36m����[2;37;0m [36mľ[2;37;0m:[1;34m����[2;37;0m [32mˮ[2;37;0m:[1;31m��˫[2;37;0m [33m��[2;37;0m:[1;33m����[2;37;0m [1;35m��[2;37;0m:[1;34m����[2;37;0m 
[1;37m��[2;37;0m:[1;31m��˫[2;37;0m [37m��[2;37;0m:[1;33m��ʥ[2;37;0m 
���滹����һЩ���֣�
����:[1;33m����[2;37;0m ����:[33m�ܸ�[2;37;0m ����:[33m�ܸ�[2;37;0m ����:[32m�ֲ�[2;37;0m ����:[31m����[2;37;0m ��ʯ:[33m�ܸ�[2;37;0m ����:[1;34m����[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 36000);
		set("weapon_prop/intelligence",48);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",45);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",37);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 46);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 65);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 84);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",7);
    set("wtypeB",8);
    set("wtypeC",12);
    set("wtypeD",0);
    set("wtypeE",16);
    set("wtypeF",8);
    set("wtypeG",12);
    set("wtypeH",0);
    set("wtypeI",10);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "hammer",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 22);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	set_amount(1);
	init_throwing(719);
	setup();
}



#include "/obj/ritem/weaponzy.h";