//Cracked by Roath
// dinningroom.c

//written by kittt



inherit ROOM; 



void create() 

{

        set("short", "����"); 

        set("long",@LONG

�������Ϊ��Ұ����Ѳ�����Ҳ��ª�úܣ������Ӱ��

�����١������˶��ڵ������̻��ʵس��š���Ķ����̲�ס��

����������������������һ�������� 

LONG);

       

      set("exits",([

        "west" : __DIR__"shibanlu5",

        "south" : __DIR__"kitchen",

])); 

        set("objects",([

                __DIR__"npc/ctxiaosi":  1

                ]));

        set("no_fight",1);



        setup(); 

        

} 

int valid_leave(object me,string dir)

{

        me=this_player();

        if(( dir=="west")

        && (present("tea",me) || present("baozi",me)|| present("mifan",me)|| present("budai",me)|| present("jitui",me)))

             return notify_fail("����һ�ѵ�סȥ·������������껹����������\n");

        return ::valid_leave(me,dir);

}

