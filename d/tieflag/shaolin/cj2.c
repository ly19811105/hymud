 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�ؾ�¥");
        set("long", @LONG
����ֻ��һ������ӣ����඼��������ʮ���������������׿����
��ʱ��ע�Լ����о��ĵ����ϣ�������ר���о������书��Ѱ������
���ڣ���Щ���������֮����Ѱ���ƽ���ɾ���֮�������Զ��ֵ���
�������ֱ�ռ���Ȼ�������һС¥�ݣ�ͨ����¥��
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"cj3",
  "down": __DIR__"cj",
]));
        set("objects", ([
                __DIR__"npc/monk20b" : 3,
       ]) );
        set("coor/x",-210);
        set("coor/y",360);
        set("coor/z",80);
        setup();
//      replace_program(ROOM); 
} 
int valid_leave(object me,string dir)
{
        object ob;
        if(userp(me) && me->query("class")!="shaolin" && dir == "up" && ob=present("shaolin monk",this_object()))
        {
        message_vision("$N��$n�����Ƕ��ֵ��Ӳ�����¥!\n",ob,me);
        return notify_fail("");
        }
        return 1;
}