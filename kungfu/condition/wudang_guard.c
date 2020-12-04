#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
     if (!duration)
{
message_vision(HIR"\n$N�����ֵʱ���Ѿ����ˣ����Խ�����(finish)��\n"NOR,me); 
      return 0;
}
  	 if( duration%2==0 
		 //&& 
		 //interactive(me) 
		 &&!environment(me)->query("no_fight")
		 && !me->is_fighting())
       {  me->start_busy(2);
          call_out("zuji", 0, me);    
     
	 }
if (!environment(me)->query("no_fight"))
{
        me->apply_condition("wudang_guard", duration - 1);
}
        return 1;
}


void zuji(object me)
{   
        object ob;
	int maxskill;
	int maxexp;
	int maxqi,maxjing;
        if (!me) return;
if (!me->query_temp("in_guard")) return;

	maxskill=me->query_skill("force");
	maxqi=me->query("max_qi")/3;
	maxjing=me->query("max_qi")/3;
	maxexp=me->query("combat_exp");
if (environment(me)->query("short")!="������")
{
tell_object(me,"�����䵱ɽ��ֵ���߿���ʧ�ܡ�\n");
me->delete("guardwd");
me->delete_temp("in_guard"); 
return;
}

if (environment(me)->query("no_fight"))
{
tell_object(me,"�����䵱ɽ��ֵ���߿���ʧ�ܡ�\n");
me->delete("guardwd");
me->delete_temp("in_guard"); 
return;
}
        tell_room(environment(me),"ɽ��ͻȻ������һ������󺺡�\n");

        ob=new("/d/wudang/npc/mengmian.c");
	if(!me->is_ghost())
{
ob->set_temp("guardtg",me->query("id"));
        ob->move(environment(me));
}
        ob->set("combat_exp",maxexp);
        if ( maxskill>5 && maxexp > 50000) {
        ob->set_skill("kuang-jian",maxskill*1/2);
        ob->set_skill("sword",maxskill*1/2);
        ob->set_skill("parry",maxskill*1/2);        
        ob->set_skill("unarmed",maxskill*1/2);
        ob->set_skill("dodge",maxskill*1/2);        
        if ( maxexp > 1000000) {
        ob->set_skill("kuang-jian",maxskill);
        ob->set_skill("sword",maxskill);
        ob->set_skill("parry",maxskill);        
        ob->set_skill("unarmed",maxskill);
        ob->set_skill("dodge",maxskill);        
}

        }
     else {
        ob->set_skill("kuang-jian",5);
        ob->set_skill("sword",5);
        ob->set_skill("parry",5);        
        ob->set_skill("unarmed",5);
        ob->set_skill("dodge",5);        
         }
        ob->set("qi",maxqi);        
        ob->set("jing",maxjing);        
	ob->set("title",HIR"�����"NOR);
	ob->kill_ob(me);
	me->kill_ob(ob);
	message_vision(HIR"\n$N����$n���һ����ɱ��!��\n"NOR,ob,me); 
        tell_room(environment(me),"ɽ��ͻȻ������һ������󺺡�\n");
        ob=new("/d/wudang/npc/mengmian.c");
	if(!me->is_ghost())
{
ob->set_temp("guardtg",me->query("id"));
        ob->move(environment(me));
}

        ob->set("combat_exp",maxexp);
        if ( maxskill>5 && maxexp > 50000) {
        ob->set_skill("kuang-jian",maxskill*2/3);
        ob->set_skill("sword",maxskill*2/3);
        ob->set_skill("parry",maxskill*2/3);        
        ob->set_skill("unarmed",maxskill*2/3);
        ob->set_skill("dodge",maxskill*2/3);        
        if ( maxexp > 1000000) {
        ob->set_skill("kuang-jian",maxskill);
        ob->set_skill("sword",maxskill);
        ob->set_skill("parry",maxskill);        
        ob->set_skill("unarmed",maxskill);
        ob->set_skill("dodge",maxskill);        
}
        }
     else {
        ob->set_skill("kuang-jian",5);
        ob->set_skill("sword",5);
        ob->set_skill("parry",5);        
        ob->set_skill("unarmed",5);
        ob->set_skill("dodge",5);        
         }
        ob->set("qi",maxqi);        
        ob->set("jing",maxjing);        
	ob->set("neili",maxqi*2);  
        ob->set("eff_qi",maxqi);        
        ob->set("max_jing",maxjing);        
	ob->set("max_neili",maxqi*2);  
	ob->set("title",HIR"�����"NOR);
	
if ( maxexp > 10000000 && random(6)==0) {
        ob->set("qi",maxqi);        
        ob->set("jing",maxjing);        
	ob->set("neili",maxqi*2);  
        ob->set("eff_qi",maxqi*2);        
ob->set("qi",maxqi);      
        ob->set("eff_qi",maxqi);        
        ob->set("max_qi",maxqi); 
        ob->set("max_jing",maxjing);        
	ob->set("max_neili",maxqi*2);  
	ob->set("jiali",50);
	ob->set_skill("sword", maxskill);
	ob->set_skill("force", maxskill);
	ob->set_skill("unarmed", maxskill);
	ob->set_skill("dodge", maxskill);
	ob->set_skill("parry", maxskill);
	ob->set_skill("anranxiaohun-zhang",maxskill);
	ob->set_skill("xuantie-sword", maxskill);
	ob->set_skill("xiantian-qigong", maxskill);
	ob->set_skill("yunv-shenfa",maxskill);
	ob->set_skill("yunv-xinfa",maxskill);
	ob->map_skill("sword", "xuantie-sword");
	ob->map_skill("parry", "anranxiaohun-zhang");
	ob->map_skill("unarmed","anranxiaohun-zhang");
	ob->map_skill("dodge", "yunv-shenfa");
	ob->map_skill("force", "yunv-xinfa");
        ob->set_temp("apply/attack", 200);
        ob->set_temp("apply/defense",500);
        ob->set_temp("apply/armor", 1500);
        ob->set_temp("apply/damage", 500);
     ob->set("str", 100);
     ob->set("dex", 100);
ob->set("title",HIB"�ڵ�����"NOR);
}
	ob->kill_ob(me);
	me->kill_ob(ob);
	message_vision(HIR"\n$N����$n���һ����ɱ��!��\n"NOR,ob,me); 
}

string query_type(object me)
{
	return "job";
}