//����

inherit ROOM;

void create ()
{
        set ("short", "ǧ�����");
        set ("long", @LONG

��һ���ž��ŵ�һ���쳣�ҷ�������,����������ǧ����Ʒ���̵�
Ů�ϰ�����Ӣ������Զ�Ķ�Ů����Ҳ����Զ�ھִ��ϰ壬��������
��ü��
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
    "east" : "/d/calvin/lanling/jie6",
        ]));

        set("objects", 
        ([ //sizeof() == 1
"/obj/boss/lanling_qianqi.c" : 1,
        ]));

//        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
