//shulin ����

inherit ROOM;

void create ()
{
        set ("short", "�Ȱ���");
        set ("long", @LONG

���������������������,����������Ƕ�ʢ
��������ο�Ҳ�����������,��������������
�Ļ��������ף��,��˵�����㷨������ͨ ...

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
        "west" : "/d/calvin/lanling/jie7",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/city/npc/keeper" : 1,
        ]));


        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

