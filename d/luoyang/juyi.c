inherit ROOM;

void create()
{
        set("short", "��н��");
        set("long", @LONG
��������ոս��ɲ��ã�һ�ж���ո�µģ����������������Ҳ�Ǹ�
�Ӿ��Ƕ����������ġ�����������С��������ɨ�أ���Ϊ������������
���ݵ��˺��١�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"xiaoxiang2",
        ]));
        set("objects", ([
                "/d/city/npc/sengren" : 1,
                "/d/city/npc/sengren1" : 2,
        ]));

        setup();
        replace_program(ROOM);
}

