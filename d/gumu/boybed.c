inherit ROOM;

void create ()
{
        set ("short", "�е�������");
        set ("long", @LONG

�������е����Է�������ǳ��ɾ�������ոձ���ɨ������������İڷ��ż�������ϯ��
LONG);

       set("exits", 
        ([ //sizeof() == 4
                  "out" : __DIR__"houting",
        ]));
        
        set("objects", 
        ([ //sizeof() == 1
  
        ]));

        set("sleep_room",1);
        set("if_bed",1);


        setup();
}
