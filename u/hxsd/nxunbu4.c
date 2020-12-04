// baoyu.c ����

#include <ansi.h>
inherit NPC;

void catched(object me,object dest);
void greeting(object ob);
int catch_pk(object me,object dest);
int waiting(object me, object dest);
int checking(object me, object dest);
void bu_move(object me);

void create()
{
        set_name( BLU "����"NOR, ({ "bao yu", "baoyu", "yu" }));        
        set("title", HIY"�Ĵ�����֮����"BLU"��"HIY"��"NOR);
        set("gender", "����");
        set("age", 32);
        set("str", 30);
        set("per", 30);
        set("dex", 30);
        set("long", "���������������µ��Ĵ��������϶�����Ȼ�书������������͵ģ�
���Ǵ������أ���ϸ�緢������һ�㶼������������ѷɫ��\n");
        set("combat_exp", 2000000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set_skill("cuff", 200);
        set_skill("force", 200);
        set_skill("sword", 200);
        set_skill("strike", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("zixia-shengong", 200);
	   set_skill("lonely-sword", 200);
        set_skill("poyu-quan", 200);
        set_skill("hunyuan-zhang", 200);
        set_skill("qiankundanuoyi", 200);
/*
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 50);
*/

        map_skill("force", "zixia-shengong");
        map_skill("cuff", "poyu-quan");
        map_skill("strike", "hunyuan-zhang");
        map_skill("sword", "lonely-sword");
        map_skill("parry", "qiankundanuoyi");
        map_skill("dodge", "qiankundanuoyi");
          
/*
        set("max_qi", 12000);
        set("max_jing", 2500);
*/
        set("neili", 4000); 
        set("max_neili", 4000); 
           set("jiali",100);

        prepare_skill("strike", "hunyuan-zhang");
        prepare_skill("cuff", "poyu-quan");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.pojian" :),
                (: perform_action, "sword.podao" :),
                (: perform_action, "sword.poqi" :),
                (: perform_action, "sword.poanqi" :),
                (: perform_action, "sword.pobian" :),
                (: perform_action, "sword.pozhang" :),
                (: perform_action, "cuff.leidong" :),
                (: perform_action, "strike.wuji" :),
                (: exert_function, "recover" :),
                (: exert_function, "heal" :),
            }) ); 
       
        set("chat_chance",4);
        set("chat_msg",({
     BLU"����"HIY"����һ����˵���������Ĵ������ڣ�˭Ҳ��Ҫɱ��...˭Ҫ��ɱ���˸������鷳�����������ȥ���Σ���\n"NOR,
     BLU"����¶���Ի�ı��飬��˼�����ҡҡͷ˵�����ף����ǰ�����ô��ôˮ��������׾ͱ�PK�ˣ�
         �ֲ���Ҫ���������Ĵ�����������\n"NOR,
        (: random_move :)
        }));
        setup();
        carry_object(__DIR__"obj/tiejia")->wear();
        carry_object(__DIR__"obj/gangjian")->wield();
//        carry_object("/clone/weapon/gangjian")->wield();
//        carry_object("/d/city/obj/tiejia")->wear()
;
}

void init()
{
        object ob;
        ::init();

        if (interactive(ob = this_player()))
                remove_call_out("greeting");
                call_out("greeting", 0, ob);
        }        

void greeting(object ob)
{
        object me;
        me = this_object();

        if(!ob || environment(ob) != environment()) return;
 	if ( ob->query("PKS") > 0 )
        {
                if ( ! is_fighting()) 
                {
                        call_out("catch_pk",0,me,ob);
                        return; 
                }
                else
                {
                        message_vision(HIC "$N��$n˵������˵���С�쵰ɱ���ˣ�����æ����������ʰ�㣡"
                                +RANK_D->query_rude(ob)+"������������������죡\n" NOR, me, ob);
                        return;
                }
        }
        else
        {
                command("say ����ģ����޽��ڷ籩�����Ҷ���Ҫ�Ʋ��ˣ�û�취��ֻ���زپ�ҵ������׽ɱ�˿��ȥ׬Ǯ��");    
//              init();
        }
        return;
}

int catch_pk(object me,object dest)
{
        if( objectp(dest) && present(dest, environment(me))
                 && !environment(me)->query("no_fight"))
        {
//              if (dest->query("qi") == 0 || dest->query("qi") <= 30 ) 
                if ( dest->query("qi") <= 40)
//              if ( dest->query("qi") == 0 )
                {
                        catched(me,dest);
                        return 1;
                }

                message_vision(HIY "$N��$n˵������˵���Ǹ�ɱ�˿�������ɱ��Ϊ�֣������������ң�
                                    ���������ˣ��ԹԵĸ��һ�ȥ�Դ��������������������"
                        +RANK_D->query_rude(dest)+"��������\n" NOR, me, dest);
                me->set_leader(dest);
                me->fight_ob(dest);
                
                dest->fight_ob(me);
               
                call_out("checking", 0,  me, dest);
                
        }
        else  
                call_out("waiting", 1, me, dest);
        
        return 1;
}

int waiting(object me, object dest)
{
        if ( objectp(dest) )
        {
                if (dest->is_ghost())
                {
                        dest->apply_condition("killer",0);
                        return 1;
                }
                else if (me->is_fighting() && present(dest, environment(me)))
                {
                        call_out("checking", 0, me);
                        return 1;
                }
                     else if (!me->is_fighting() && present(dest, environment(me)))
                     {
                              call_out("checking",0,me);
                              return 1;
                     }                  
        }               
        
        remove_call_out("waiting");
        call_out("waiting", 10, me);
    return 1;
}

int checking(object me, object dest)
{
        object ob;
        
        if (me->query("qi") == 0)
                return 1;

        if (me->is_fighting()) 
        {
                call_out("checking",0,me);              
                return 1;
        }
        else  init();

        if (objectp(ob = present("corpse", environment(me)))
                 && ob->query("victim_name") == dest->query("name") )
        {
                dest->apply_condition("killer",0);
                me->set_leader(0);
                            me->set("PKS",0);
                return 1;
        }

//      if (dest->query("qi") == 0 || dest->query("qi") <= 30 ) 
        if ( dest->query("qi") <= 40 )
        {
//      if ( dest->query("qi") == 0 )
//              command("say �����checking()�ڹ���");
				catched(me,dest);
                return 1;
        } 
        else if (dest->query("qi") > 0) init();

        call_out("waiting", 0, me, dest);
        return 1;
}

void catched(object me,object dest)
{       
//      command("say "+(string)dest->query("id")+(string)dest->query("qi"));
        
        dest->apply_condition("gvmt_jail", 30);
        dest->unconcious(); // ����
//      command("get "+(string)dest->query("id"));
        command("say ��������������ô����è�Ĺ��򻹸ҳ�����ɱ�˿����Ѿ�û���ˣ�����ɣ�" );
        message_vision(HIC"ֻ����������һ����$N�׳��������˷���ס��Ѻ����"+(string)dest->query("name")+"������ط����ȥ��\n"NOR,me);

        dest->move("/d/gvmt/jianyu_do");
        me->move("/d/gvmt/jianyu_do");

        me->set("startroom", "/d/gvmt/jianyu_do");
        me->set("PKS",0);
       dest->apply_condition("killer",0);
//      command("drop "+(string)dest->query("id"));
        me->set_leader(0);
                
        message_vision(HIC"$N���˿���ĭ����"+(string)dest->query("name")+"���ص����ڵ��ϣ��ݺݵ�����һ�ţ�����һ��������Ьӡ��ת�����������뿪��\n"NOR,me);
        bu_move(me);
        return;
}
 

void bu_move(object me)
{
        switch ( random(6) )
        {
        case 0 :
                me->move("/d/city/kedian"); // ����
                break;
        case 1 :
                me->move("/d/city4/center"); // ����
                break;
        case 2 :
                me->move("/d/city3/kedian"); // ����
                break;
              case 3 :
                me->move("/d/kunming/kedian"); // �ɶ�
                break;
        case 4 :
                me->move("/d/jyguan/kedian"); // ����
                break;
        case 5 :
                me->move("/d/city2/kedian"); // ����
                break;
        }  
        message_vision("$N���˹�����\n",me);
                
        return;
}


void die()
{
        object ob;
        message_vision("$N���ڵ���,�����˼���,���ˡ�\n", this_object());
        ob = new("/cao/bukuai");
        destruct(this_object());
}