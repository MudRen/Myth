inherit ROOM;

void create()
{
        set("short", "�ƾ��Գ�");
        set("long", @LONG
�����Ŀƾ��Գ������������ֵ�һ��������ÿ�³�һ��ȫ�����ص�ʿ
�Ӷ����˴��Ͽ���Ժ��������ʿ�����أ�Ҫ��д��ɲ��У�Χǽ��������
���ĸ�ʾ��
LONG);
        set("objects", ([
                "/d/luoyang/npc/shusheng1" : 2,
                "/d/luoyang/npc/shusheng2" : 2,
        ]));
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"nroad3",
        ]));

        setup();
        replace_program(ROOM);
}

