// migong lev2

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name("���߻�", ({ "tiger", "laohu" }));
      
          set("race", "Ұ��");
       set("long",
"һֻ����Ѫ���ڵİ���ͻ���
\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "ͷ��", "����", "ǰצ", "��ץ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
	       set("max_qi",700+random(700));
  set("max_jing",700+random(700));
  set("max_sen",700+random(700));
  set("max_mana",700+random(700));
  
      set("dex",40);
     set("str",40);
       
    set("age", 5);

        set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 700000);
                  
        set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/defence",100);

   setup();

        

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
        message_vision(WHT"$Nһ���ҽ�,���ڵ��ϣ����˸���ͷ�Ͳ������ˡ�\n"NOR,ob,me);
exp=8+random(5);
        if((int)me->query("combat_exp") < 800000) exp=exp*5;
pot=exp*3/4;
        message("vision", me->name() + "�����"+exp+"�㾭���"+pot+"��Ǳ�ܡ�\n", me);
        me->add("combat_exp",exp);
        me->add("potential",pot);

	::die();
}