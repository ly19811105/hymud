inherit NPC;
void create()
{
   set_name("����",({ "che fu","che","fu" }) );
        set("gender", "����" );
        set("age", 22);
   set("long", "����һ����ͨ�ĳ���\n");
   set("combat_exp", 20000);
   set("attitude", "friendly");
   set_temp("apply/damage",30);
   set_temp("apply/dodge",30);
   set_temp("apply/armor",30);
   set("chat_chance",20);
   set("chat_msg",({
   	"�������������ι���������лл�ˣ�\n",
   	(:random_move:),
   	}));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}