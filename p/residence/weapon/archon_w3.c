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
	set_name("[1;32m�޼�֮��[2;37;0m", ({ "wuji sword", "sword" }));
	set_weight(5300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[1;32m�����Ѵ�����뻯���Ƿ��켫���������֮���磡��˵������ڣ������⡰�޼�����
[2;37;0m����һ���ɾ��Լ�Ӳ��[37m����[2;37;0m�Ƴɣ���ʮ��������Ǯ��[1;32m�޼�֮��[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m ���������Է���������[1;31m������˫[2;37;0m��������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;31m��˫[2;37;0m [36mľ[2;37;0m:[31m����[2;37;0m [32mˮ[2;37;0m:[1;33m��ʥ[2;37;0m [31m��[2;37;0m:[1;34m����[2;37;0m [33m��[2;37;0m:[35m��׼[2;37;0m [1;37m��[2;37;0m:[1;34m����[2;37;0m 
���滹����һЩ���֣�
����:[1;33m����[2;37;0m ����:[34mϸ��[2;37;0m ����:[34mϸ��[2;37;0m ��ʯ:[32m�ֲ�[2;37;0m ����:[32m�ֲ�[2;37;0m 
����:[34mϸ��[2;37;0m ����:[35m��׼[2;37;0m ����:[32m�ֲ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m����[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "archon");
		set("ownername", "����");
		set("value", 25000);
		set("weapon_prop/intelligence",40);
		set("weapon_prop/strength",40);
		set("weapon_prop/karey",56);
		set("weapon_prop/percao",29);
		set("weapon_prop/dexerity",40);
		set("weapon_prop/constitution",26);
    set("weapon_prop/dodge", 37);
    set("weapon_prop/parry", 40);
    set("weapon_prop/attack", 48);
    set("weapon_prop/armor", 40);
    set("weapon_prop/defense", 48);
    
    set("weapon_prop/neili", 27);
    set("weapon_prop/qi", 55);
    set("weapon_prop/jing", 30);
    set("weapon_prop/jingli", 30);
    set("weapon_prop/damage", 0);

    set("wtypeA",12);
    set("wtypeB",6);
    set("wtypeC",10);
    set("wtypeD",8);
    set("wtypeE",5);
    set("wtypeF",6);
    set("wtypeG",8);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",4);
    set("wtypeL",4);
    

                set("skill", ([
                        "name": "axe",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 16);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_sword(1615);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";