#include <ansi.h>

inherit VRM_SERVER;

#define ENTER_ROOM_X    0
#define ENTER_ROOM_Y    0
#define ENTER_ROOM_Z    0

void create()
{
	// �Թ��������̳е�����ĵ������ơ�
	set_inherit_room( ROOM ); set("no_clean_up",1);

	// �Թ�����Ҫ����͵ȼ���

        set_lonely_create(1);


        //�Թ�������Ĺ�� 
        set_maze_npcs( ([
                __DIR__"npc/lev1": random(2),
                __DIR__"npc/lev2": random(2),  
                __DIR__"npc/lev3": random(2), 
                __DIR__"npc/lev4": random(2), 
                __DIR__"npc/lev5": !random(3), 
                __DIR__"npc/lev6": !random(4), 
                __DIR__"npc/leva": !random(4), 
                __DIR__"npc/levb": !random(4), 
                __DIR__"npc/player": !random(8), 
        ]) );  

	// �Թ��еĹ�����ֿ�����
        //set_npcs_rate(50);

	//�Թ��������BOSS��
        set_exit_npcs(__DIR__"npc/boss1");

	//�Թ��ĵ��߳�
        set_maze_long(6); 

        set_npcs_rate(66);
        
        //set_lonely_create(1);


        set_maze_boxs(2);
        set_maze_traps(4); 

	//��ڷ���(�����ڶ���)
	set_entry_dir("north");

	//�������������ӷ���
	set_link_entry_dir("north");

	//�������������ӵ�����
	set_link_entry_room(__DIR__"out");

	//��������������ӷ���
	set_link_exit_dir("south");

	//��������������ӵ�����
	set_link_exit_room(__DIR__"out2"); 

	//��ڷ��������
	set_entry_short(HIG"ˮ��֮��"NOR);

	//��ڷ�������
	set_entry_desc(HIG @LONG
    �������ں����ϣ��������ϡ����������ꡣ����������һ���ŵķ����֣�֦��
��Ӳ��ϸϸ�����ģ���ľ���һ���ֲ�������һƬ����Ĵ󺣣����˲�ͣ����
�����µ̡�
LONG
);

	//BOSS���������
	set_exit_short(HIG"ˮ��֮�ݵľ�ͷ"NOR);

	//BOSS��������
	set_exit_desc(HIG"
    �������ں����ϣ��������ϡ����������ꡣ����������һ���ŵķ����֣�֦��
��Ӳ��ϸϸ�����ģ���ľ���һ���ֲ�������һƬ����Ĵ󺣣����˲�ͣ����
�����µ̡�
"NOR);

	//�Թ�����Ķ�����
	set_maze_room_short(HIG"ˮ��֮��"NOR);

	//�Թ����������������ж�������������ÿ����
	//���ʱ���������ѡ��һ����
	set_maze_room_desc(HIG @LONG
    �������ں����ϣ��������ϡ����������ꡣ����������һ���ŵķ����֣�֦��
��Ӳ��ϸϸ�����ģ���ľ���һ���ֲ�������һƬ����Ĵ󺣣����˲�ͣ����
�����µ̡�
LONG
);


        // �Թ��ݻ�ʱ��
        set_remove_time(3000); 

	// �Թ������Ƿ�Ϊ���ⷿ�䣿
	set_outdoors(1);
}