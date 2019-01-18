// book.c: a file that all non-skill books will inherit
// created 9-26-97 pickle

#include "book.h";

mapping toberead=([]);

int read_book(object me,string name)
{
        object obj,ob;
        int fuyuan,chance,fuyuanchance;
	obj=this_object(); 
  	fuyuan = (int)me->query_kar();
  	chance = random(1000);
  	fuyuanchance = (fuyuan * fuyuan);

      //    checks if the book's been read too many times.
      //    avoids abuse by players to keep reading the same book with a robot
      //    another layer of protection is that the bookstore only sells 30
      //    books each refresh, which means that a player has 90 times to try
      //    at getting something. and the chance of getting a guo is, for the
      //    player with the best fuyuan, about 1 per refresh.

  if (toberead[name] == 3) 
    {
      message_vision("ֻ��" + obj->query("name") + "����ƬƬ��м����$N������Ʈ�䡣\n", me);
      call_out("destroy", 1, obj);
      tell_object(me, "���Ѿ��������ˣ���һ���µİɣ�\n");
      return 1;
 }

//     if passes check then test what the player may get
//     first checks for guo, 10% times the kar squared / 100000
//     so for kar 30, 10% times 9/100 or about 1%
//     and for kar 10, only 0.1%

  if ((chance < 10) && (random(100)*100 < fuyuanchance))
    {message_vision(GRN "$N����һ��"+ obj->query("name")+"��ֻ���鱾�����ģ���æ������\n" NOR, me);
     message_vision(GRN "����Ʈ��һ��ֽ������д����������ǧ���ڡ�\n", me);
     message_vision(GRN "$N��ͷһ������Ȼ����������һö����ɫ�ĵ�ҩ��\n", me);
     message_vision(GRN "$N�������������˵�ҩ��ȴһ��С�ģ��������ˮ�����ˡ�\n" NOR, me);
     ob = new("/d/obj/drug/guo");
     ob->move(me);
        call_out("destroy", 1, obj);
     return 1;
    }
//    if doesn't get guo, then check for tao.
//    tao is at similar chance. 10% times kar/1000
//    if kar is 30, then about 0.3% chance.
//    if kar is 10, then only 0.1% chance again.

  if ((chance < 10) && (random(100)*10 < fuyuan))
    {message_vision(YEL "$N����һ��"+ obj->query("name")+"��ֻ���鱾�����ģ���æ������\n" NOR, me);
     message_vision(YEL "����Ʈ��һ��ֽ������д����������ǧ���ڡ�\n", me);
     message_vision(YEL "$N��ͷһ������Ȼ����������һ��⨺��ң�\n", me);
     message_vision(YEL "$N��������������⨺��ң�ȴһ��С�ģ��������ˮ�����ˡ�\n" NOR, me);
     ob = new("/d/obj/drug/mihoutao");
     ob->move(me);
        call_out("destroy", 1, obj);
     return 1;
    }

//    if still not, then checks for gold.
//    20% times kar/100, which is quite generous. =}
//    kar 30 means 15%, kar 10 means 5%.

  if ((chance < 10) && (random(100)*5 < fuyuan))
    {message_vision(HIY "$N����һ��"+ obj->query("name")+"��ֻ���鱾�����ģ���æ������\n" NOR, me);
     message_vision(HIY "����Ʈ��һ��ֽ������д���������лƽ��ݡ�\n", me);
     message_vision(HIY "ֻ����������һ������Ȼ����������һ���ƽ�\n", me);
     message_vision(HIY "$N�������������˽��ӣ�ȴһ��С�ģ��������ˮ�����ˡ�\n" NOR, me);
     ob = new("/obj/money/gold");
     ob->move(me);
        call_out("destroy", 1, obj);
     return 1;
   }
  write("\n");
  this_player()->start_more(read_file("/d/obj/books-nonskill/text/"+name));
  toberead[name]++;
  return 1;
}

void destroy(object obj)
{
        destruct(obj);
        return;
}
