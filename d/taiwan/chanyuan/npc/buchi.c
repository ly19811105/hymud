
inherit NPC;
inherit F_MASTER;

#include <ansi.h>


void create()
{
   int i;
   object *ob;

   set_name("����",({ "bu chi","bu","chi"}));
        set("gender", "����" );
        set("age", 32);
   set("long", "���Ǿ�����Ժ���Ĵ󻤷����֮һ��\n");
   set("class","bonze"); 
   set("combat_exp", 600000);
   set("str", 28);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("staff",150);
   set_skill("force",150);
   
         set_skill("unarmed", 200);
        set_skill("dodge", 100);
		set_skill("move", 100);
        set_skill("staff", 200);
        set_skill("force", 180);
        set_skill("parry", 150);
        set_skill("literate", 140);
        set_skill("iron-cloth", 230);
        set_skill("bloodystrike", 150);
        set_skill("lamaism", 200);
        set_skill("jin-gang", 200);
        set_skill("spells",200);

        
        
        map_skill("unarmed", "bloodystrike");
        map_skill("iron-cloth", "jin-gang");
        
        set_temp("apply/iron-cloth",200); 
        
	set_skill("iron-cloth", 150);

	set_skill("bloodystrike", 300);
	set_skill("cloudstaff", 300);
	set_skill("bolomiduo", 300);
	set_skill("buddhism", 300);
        set_skill("jin-gang", 350);


	map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("literate", "buddhism");
        map_skill("iron-cloth", "jin-gang");
        map_skill("staff", "cloudstaff");
        map_skill("parry", "cloudstaff");        
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.siqijinlong" :),
                (: perform_action, "staff.longxianyuye" :),
        }) );
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);    
   
   set("max_jing",2000);
   set("max_qi",2000);
   set("max_sen",2000);
   set("max_neili",2000);
   set("neili",2000);
   

   set("perform_quest/fumo",1);
   create_family("������Ժ",5,"����");
   setup();
   
   ob=children(__DIR__"obj/xiangmo-zhang");
   for(i=0;i<sizeof(ob);i++)
     if(environment(ob[i])&&userp(environment(ob[i]))){
     tell_object(environment(ob[i]),"�����е�"+ob[i]->query("name")+"�����������ջ�ȥ�ˣ�\n");
     if(ob[i]->query("equipped"))
      ob[i]->unequip();
     destruct(ob[i]);}
     else if(environment(ob[i])){
     tell_object(environment(ob[i]),ob[i]->query("name")+"��һ�������ˡ�\n");
     destruct(ob[i]);}
     else destruct(ob[i]);

   carry_object(__DIR__"obj/xiangmo-zhang")->wield();
  
}
