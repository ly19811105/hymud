// migong lev10  ������ʽ

#include <ansi.h>

inherit NPC;


string* names = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʩ","��",
"��","��","��","��","��","κ","��","��","��","л","��","��",
"��","ˮ","�","��","��","��","��","��","��","��","��","��",
"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��",
"��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʱ","��",
"Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��",
"��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��",
"��","��","֧","��","��","��","¬","Ӣ","��","��","��","˧",
"˾��","�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�",
"ξ��","����","�̨","����","����","���","����","����","̫��",
"����","����","����","ԯ��","���","����","����","����","Ļ��",
"˾ͽ","ʦ��","��","��ľ","����","����","���","����","����",
"����","��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��",
"��ǧ","����","����","�Ϲ�","����","�麣","����","΢��","����",
"����","����","����","����","�Ϲ�",

"��","��","��","��","��","��","��","Ĳ","��","��","ī","��",
"��","��","��","��","١","��","��","��","��","��","��","��",
"��","ʯ",
});

string* nm2 = ({
"��","Т","��","��","��","��","��","��","��","��","��","»","��","С","��",
"��","��","��","��","��","��","��","֮","��","��","ʱ","��","��","��","��",
"��","��","��","��","��","��","��","��","Ϊ","��","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm3 = ({
"��","��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","�","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","��","��","��","ǿ","��","ɽ",
"̩","��","ͦ","ΰ","��","��","��","��",
"��","�","��","��","��","��",
});


void create()
{
  
       int i = random(sizeof(names));
   set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], 
 ({ "man" }));
 
set("title", YEL"а������"NOR);
   set("gender", "����" );
 set("long",
"�޶����Ľ������ࡣ\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",100+random(200));
  set("max_qi",5500+random(2000));
  set("max_jing",5500+random(2000));
  set("max_sen",5500+random(2000));
  set("max_neili",5500+random(2000));
  set("max_mana",5500+random(2000));
  set("eff_neili",5500+random(2000));
  set("neili",5500+random(2000));
        set("per", 1);
        set("age", 32);

       set("jiali" , 100);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 4000000+random(2000000));
                 set_skill("blade", 360+random(60));

set_skill("hand", 360+random(60));

set_skill("shenlong-xinfa", 360+random(60));

set_skill("force", 360+random(60));
set_skill("shenlong-bashi", 360+random(60));

set_skill("parry", 360+random(60));

set_skill("dodge", 360+random(60));

set_skill("shedao-qigong", 360+random(60));

set_skill("zhaosheshu", 360+random(60));

set_skill("yixingbu", 360+random(60));

  
        map_skill("hand", "shenlong-bashi");
  
      map_skill("parry", "shedao-qigong");

 map_skill("force", "shenlong-xinfa");

 map_skill("dodge", "yixingbu");
 
prepare_skill("hand", "shenlong-bashi");
set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
 
      (: perform_action, "hand.flower" :),
	
        (: exert_function, "recover" :),
       (: exert_function, "powerup" :),
    (: perform_action, "hand.yingxiong" :),
	
    (: perform_action, "hand.shenlongtuwu" :),
	
    (: perform_action, "hand.bada" :),
	
  (: perform_action, "parry.chang" :),
	
(: perform_action, "hand.chang2" :),
	
   (: perform_action, "hand.flower" :),

 }) );
            set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
 
          set_temp("apply/armor", 150);
        set_temp("apply/damage", 150);

     set("chat_chance", 30);
        set("chat_msg", ({
		(: command("get silver") :),
		(: command("get gold") :),
		(: command("get coin") :),
                (: random_move :),
           }) );
        setup();

        carry_object("/d/migong/obj/cloth")->wear();
  
carry_object("/d/migong/obj/blade")->wield();
      
add_money("silver", random(10));


}

void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
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

void die()
{
        object ob, me, corpse;int exp,pot;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        if (!me) return;
             me->add("score",1);
        me->add("shen",10);

        message_vision(WHT"$N������Ѫ����,���ض�����\n"NOR,ob,me);
exp=40+random(20);
        if((int)me->query("combat_exp") < 7000000) exp=exp*5;
pot=exp*3/4;
        message("vision", me->name() + "�����"+exp+"�㾭���"+pot+"��Ǳ�ܡ�\n", me);
        me->add("combat_exp",exp);
        me->add("potential",pot);

	::die();
}