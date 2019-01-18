inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "��̶");
        set("long", HIR @LONG   
���������̶��һֻ�����̾�������������˽���������һ��
����޺�Ȼ��㷢���˹�������˵���ػ��ž������������ı��ء�
�пյĻ�������(search)һ�»�������ջ�
LONG);
        set("exits", ([ 
              "south" : __DIR__"spirit6", 
           ]));
        set("objects", ([ 
             "/d/quest/tulong/npc/dragon" : 1,
          ]));
        set("book_count", 7);

        setup();
} 

void init()
{
  add_action ("do_search","search"); 
  add_action ("do_quit","train");}

int do_quit(string arg){
        write(this_player()->query("name")+"����Ҳ�ǿ���ѱ��ô����\n");
        return 1;
} 
int do_search (string arg)
{
  object who = this_player ();
  object where = this_object ();
  object book;

 if (query("book_count") < 1) 
  {
    message_vision ("$N�Ĵ�������һ����ʲôҲû���ҵ���\n",who);  
    message_vision ("Ҳ���Ǳ��ù��ˡ�\n",who);  
    return 1;
  }
        if (  present("happy diary", who) ) {
                return notify_fail("�㶼���Ȿ���ˣ���Ҫ��ʲô��\n");
          }
 if (who->query_temp("mark/diary")) 
   {
    message_vision ("$N�Ĵ�������һ����ʲôҲû���ҵ���\n",who);  
    message_vision ("�������ǲ��ܶ��õġ�\n",who);  
    return 1;
  }

  if (random(10))
  {
    message_vision ("$N�Ĵ�������һ����ʲôҲû���ҵ���\n",who);  
  }
  else
  {
    book = new ("/d/quest/tulong/obj/diary");
    message_vision ("$N���ӿ���Ҷ���ҳ�һ��"+MAG"�����ռ�"NOR+"��\n",who,book);
    who->set_temp("mark/diary", 1);
    book->move(who);  
    message("channel:rumor", HIR"��������硿ĳ�ˣ�"+this_player()->query("name")+"�ҵ������ռ�����\n"NOR, users());
    add("book_count", -1);
  }
  return 1;
}


