// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit SWORD;

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
	set_name("[1;37m�����鳤��[2;37;0m", ({ "good sword", "sword" }));
	set_weight(7582);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
�һ�֮��[2;37;0m����һ���ɼ�Ϊ��Ӳ��[31m����ʯ[2;37;0m�Ƴɣ���ʮ���һ����Ǯ��[1;37m�һ�֮��[2;37;0m��
�ۺ�����[1;34m��������[2;37;0m ��������Ϊ����������[1;36mն����ħ[2;37;0m��������
������˼����ŷ��ţ�
[40m��[2;37;0m:[1;36m����[2;37;0m [1;36m��[2;37;0m:[1;34m����[2;37;0m [1;31mħ[2;37;0m:[1;33m��ʥ[2;37;0m [1;33m��[2;37;0m:[32m�ֲ�[2;37;0m [36mľ[2;37;0m:[1;32mħ��[2;37;0m [1;35m��[2;37;0m:[1;32mħ��[2;37;0m 

���滹����һЩ���֣�
����:[1;33m��ʥ[2;37;0m ����:[33mһ��[2;37;0m ��ʯ:[36m����[2;37;0m ����:[33mһ��[2;37;0m 
����:[34mϸ��[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m�޵�[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "wudi");
		set("ownername", "�޵�");
		set("value", 9000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",9);
		set("weapon_prop/karey",40);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 18);
    set("weapon_prop/attack", 9);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 32);
    set("weapon_prop/qi", 40);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 32);
    set("weapon_prop/damage", 0);

    set("wtypeA",3);
    set("wtypeB",9);
    set("wtypeC",5);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",9);
    set("wtypeG",0);
    set("wtypeH",3);
    set("wtypeI",0);
    set("wtypeJ",1);
    set("wtypeK",8);
    set("wtypeL",10);
    

                set("skill", ([
                        "name": "sword",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 10);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_sword(629);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";