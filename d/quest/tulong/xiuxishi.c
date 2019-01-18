inherit ROOM; 
#include <ansi.h> 
void create ()
{
  set ("short", "��Ϣ��");
  set ("long", HIG @LONG
���￴��ȥ����һ����Ϣ�ң�����������ż������ӣ�������
һЩС�ˣ��ݽ���һ������(closet)�������洫���˱ǵ���������
�˴��ѡ�������ȡůװ�ã�������ů�紺��
LONG);

  set("item_desc", ([
     "closet" : "һ�����ƵĹ��ӣ����������(cigarette)����(wine)���ǹ�(sugar)��������(take)������Ŷ��\n",
   ]));
  set("exits", ([
        "north"    : __DIR__"spirit5",
        "east"    : __DIR__"spirit4",
        "west"    : __DIR__"liechang",
      ])); 
  set("objects", ([ 
      ]));
        set("no_fight", 1);
        set("sleep_room",1);

  setup();
}

void init()
{
        add_action("do_take", "take");
}

int do_take(string arg)
{
        object me=this_player();
        object ob;
        if(!arg) return notify_fail("��Ҫ��ʲô��\n"); 
        if(arg=="wine"){
        ob = new ("/d/quest/tulong/obj/wine");   
        ob->move(me); 
        message_vision ("$N�ӹ����ó�$n��\n",me,ob);   
        return 1;
        }
        if(arg=="sugar"){
        ob = new ("/d/quest/tulong/obj/sugar");   
        ob->move(me); 
        message_vision ("$N�ӹ����ó�$n��\n",me,ob);   
        return 1;
        }
        if(arg=="cigarette"){
       ob = new ("/d/quest/tulong/obj/cigarette");   
       ob->move(me); 
        message_vision ("$N�ӹ����ó�$n��\n",me,ob);   
        return 1;
        }
        else
        write("������û������������\n");
        return 1;  
}
int valid_leave()
{
        if((present("wine", this_player())))
            return notify_fail("�벻Ҫ��������Ķ�����\n"); 
        if((present("sugar", this_player())))
            return notify_fail("�벻Ҫ��������Ķ�����\n"); 
        if((present("cigarette", this_player())))
            return notify_fail("�벻Ҫ��������Ķ�����\n"); 
        if((present("budai", this_player())))
            return notify_fail("����²���������Ķ������ܴ���ȥ��лл��\n");

    return ::valid_leave();
}

