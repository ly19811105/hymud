// Room: god2
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"ʥ��"NOR);
        set("long", HIC @LONG
�㲽�絽ʥ���С�ʥ����Ŀռ��Եø���Ĵ���̧��ͷ����������������
������ʮ��������������ȥ��Ҳ��֪���ж�ߡ����������У�����Լ����ǰ��һ
��ƽ̨����һ�ѽ��Σ������ƺ����Ÿ���˼�����ˣ�����ȴ�������������ݣ���
��������ǰȥ��ȴ��һ��������������㵲�˻���������¾�����������ɣ���
λ����Ӧ�þ�������˰ɡ�
�������������м䣬��һ�����������ʯ�������������������ӣ������裬
ԭ���Ǻ����ö������־���������������ġ�������ʥ���У���ֻ�����Ҹ��Ͱ�
�꣬���ԭ�����������ġ������ǣ���ȴ������������������壬���ɿ�ʼ����
�����������ӵĳ���������
LONG
NOR   );
        set("deathroom",1);
        set("no_clean_up", 0);
        setup();
}

void reset()
{
        ::reset();
        set("exits", ([ /* sizeof() == 1 */
            "down" : __DIR__"god1",
        ]));
}

int valid_leave(object me, string dir)
{
        switch(dir) {
        case "down":    write(HIW"�����뿪ʥ�����𣿡�\n\n"NOR);break;
        default:
                        write(HIG"�㲻Ը����������������ĵط��𣿡���\n\n"NOR);
        }
        write(HIB"��Ȼ����Ȼ����������Ǿ�ȥ�ɡ���\n\n\n\n"NOR);
        write(HIY"��һƬ�����У��������뿪��ʥ�����\n\n\n\n"NOR);
//        this_player()->add("shen", (int)this_player()->query("shen") / 9);
        return 1;
}