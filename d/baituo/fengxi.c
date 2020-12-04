#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��϶");
        set("long", @LONG
������ʯ����ʯ��֮��ļз죬���߻谵�������Ըо������ܵ�ɳɳ
���Ǹ��ֶ������е�������һ�ɹ���ζ��Ҳ������һЩ�̱ǵ���Ϣ���㷢
��ǰ����һʯ��(shikuai) �������������Ĺ�â��
LONG);
        set("objects", ([
                    __DIR__"npc/yanjing" : 2
        ]));
        set("exits", ([
              "north" : __DIR__"fengxi1",
              "out" : __DIR__"yuanzi2",
        ]));
         set("item_desc", ([                    
                "shikuai": BLU"\n���ʯͷ������ɫ��ɢ������������ʯ���ϰ��ݽ�ȥ���Ǹ����������Ρ�\n"NOR,
        ]));
        setup(); 
}

void init()
{
        add_action("do_push", "tui");
        add_action("do_push", "push");      
}

int do_push(string arg)
{
        object me = this_player();
        if( !arg || arg=="" ) return 0;
        
        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("����æ���ء�\n");
        	
        if( (int)me->query_temp("baituo_stone") ) 
                return notify_fail("���Ѿ��ƶ�����ʯ�顣\n");
                
        if (arg == "shikuai" ){   
           	message_vision("$N�������˿�����������ְ�סʯ���ϵ���ӡ������������ȥ��\n", me); 
           	me->set_temp("baituo_stone", 1);
           	message_vision("$N��ʯ�鰴�´���������ԼԼ�������´���һ���¡����\n", me); 
           	me->start_busy(5);      
           	call_out("poisoned", 5, me);
        }     
        return 1;
}

int poisoned(object me)
{
        if(!me) return 0;
        
        if ((int)me->query_skill("poison", 1) < 50 &&
             !me->query_skill("hamagong", 1)){
               tell_object(me, BLU "��е�ʯ���ϵ�����˳���ֱ���������������\n\n" NOR );
               message_vision("$NͻȻ����һ�������������˺�����\n", me);
               me->apply_condition("cold_poison", me->query_condition("cold_poison")+50);
               return 1;
               }   
        else {
               tell_object(me, BLU "��Ȼһ������˳���ֱ۴�ʯ������������������\n\n" NOR );
               tell_object(me, HIW "����æ�˹��������������ֱ۵ĺ����������˳�ȥ��\n" NOR );
               return 1;
               }           
}