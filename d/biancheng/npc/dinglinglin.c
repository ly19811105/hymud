#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";  
inherit NPC;
void create()
{
        set_name("������",({"ding linglin","ding","linglin"}));
        set("title","Ҫ����");
        set("long","�����ż���ƮƮ���°����ӣ�ѩ�׵Ĳ����ϣ����Ÿ���ȦȦ����ȦȦ�ϻ�������ö
�����ɡ�������Ҳ���Ÿ���ȦȦ����������ö�����ɣ��紵����ʱ��ȫ�������ɾ͡������塱
���졣��\n");
        set("gender","����");
        set("age",32);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",4000000);  
        set("attitude", "friendly");
        
        
        set("death_msg",CYN"\n$N�ں޵�˵�����ҵĽ��������ǡ������εá���̫������������\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );  */
        set("chat_chance",1);
        set("chat_msg",({
                "������Ц�û�֦��չ��ȫ��������Ҳ��ʼ�������塱��ֱ�졣\n",
                "������Ц�ˡ���Ц������ʱ�����ϵ��嵵���ڡ������塱���죬��������Ц��һ����
�ö��ˡ�\n",
        }) );                   
        
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
    
}     