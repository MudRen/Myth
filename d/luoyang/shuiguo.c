inherit ROOM;

void create()
{
        set("short", "ˮ����");
        set("long", @LONG
���ˮ����ط����󣬵�ȴ���ŷḻ��ˮ��Ʒ�֣����㽶��ƻ������
�ӣ����棬���ϣ���֦�ȵȣ�����������֦��������ʫ�ƣ��������֦��
�ٿţ����ǳ��������ˡ����ɼ������ǵ��ؾ����������οͶ���ϲ����
�����
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"sroad6",
        ]));
        set("objects", ([
//                __DIR__"npc/xiaofan" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

