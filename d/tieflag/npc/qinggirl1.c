 inherit NPC;
void create()
{       
        object armor;
        set_name("�ֽ���������Ů", ({ "sword girl" }) );
        set("long", "һ�������������������µ���Ů��\n");
        set("age", 16);
        set("per",20);
        set("cps",40);
        set("gender", "Ů��");
        set("attitude", "friendly");
        set("combat_exp", 1800000);  
        
        set_skill("ill-quan",150);
        set_skill("unarmed",150);
        set_skill("force",150);
        set_skill("cloudsforce",150);
        set_skill("dodge",150);
        set_skill("parry",130);
        set_skill("tie-steps",150);
        set_skill("sword",100);
        set_skill("fy-sword",120);
        
        set("max_neili",500);
        set("neili",500);
        set("force_factor",20);
        
        map_skill("force","cloudsforce");
        map_skill("dodge","tie-steps");
        map_skill("unarmed","ill-quan");                         
        map_skill("sword","fy-sword");
        map_skill("parry","fy-sword");
        map_skill("dodge","tie-steps");
        
        set("no_busy",4);
        set("resistance/kee",10);
        
        create_family("������", 4, "����");
        setup();
        
        armor=new(__DIR__"obj/corclot");
        armor->set_name("����ȹ",({"cloth"}) );
        armor->move(this_object());
        armor->wear();
        carry_object("/clone/weapon/gangjian")->wield(); 
}       