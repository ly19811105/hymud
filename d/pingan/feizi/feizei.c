// feizei.c
//����(lywin)2000/5/30Ϊһ������ϵͳд��npc

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("Сë��",({ "mao zei","zei" }) );
	set("title",HIY"����ݵ�"NOR);
        set("gender", "����" );
        set("long", 
"�����޶�����Сë����������һ��СС�������������ǲ�͵�˲������ӡ�\n");

	set("int", 30);
	set("str", 25);
	set("con", 25);
	set("dex", 25);
        set("attitude", "aggressive");
        set("shen_type", -1);

  set("combat_exp", 1000+random(300000));
  set("age", 10+random(30));
  set("per", 14+random(50));
  set("force_factor",2+random(190));
  set("force_factor",2+random(190));
  set("max_qi",100+random(200));
  set("max_jing",100+random(200));
  set("max_sen",300+random(200));
  set("max_neili",300+random(200));
  set("max_mana",300+random(200));
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 20);

  set_skill("unarmed", 10+random(190));
  set_skill("dodge", 100+random(190));
  set_skill("parry", 10+random(190));
  set_skill("sword", 10+random(190));
	
	set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) );

        setup();
        carry_object( __DIR__ "changjian")->wield();
	carry_object( __DIR__ "cloth")->wear();
  add_money("silver", random(10)+10);
}
void init()
{
        remove_call_out("hunting");
	if(!environment()->query("no_fight"))
        call_out("hunting",1);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
                if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
		if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}
