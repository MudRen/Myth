//�������¹�
//by junhyun@SK

inherit ROOM;

void create ()
{
        set ("short", "�ؾ���");
        set ("long", @LONG

���ߵ����������������д���˴ӹ���������������ߺ���,
���������������µ�ǧ�Ŵ��������ع���,�������Ϸ�ȴ��һ��
                     ��������������������������
�������,����д��:   ����  ��  ��  ��  ��  ���� �ĸ����֡�
                     ��������������������������


LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "north" : "/d/club/moongirl/huayuan2", 
       "west" : "/d/calvin/lanling/npcroom1"   
        ]));

        set("objects", 
        ([ //sizeof() == 1

        ]));

        set("indoors", "�ؾ���");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


