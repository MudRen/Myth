//Cracked by Roath

#include <room.h>
inherit HOCKSHOP;

object cart;
object findcart();
void expire();

void create ()
{
  set ("short", "Ǯׯ������");
  set ("long", @LONG

һ��䱸ɭ�ϵĵ����ң�ר���ṩ�Ĵ�����������
����Ĵ�(jicun)��Ʒ���۸񹫵���������Ʒ�����һ��
ÿСʱ����һ���������ڲ�ȡ(qu)����Ʒû�պ���ÿ��
����ʮ���ĵͼ۹�������(pick box)��

LONG);

  set("exits", ([ /* sizeof() == 1 */
       "up" : "/d/city/bank",
]));

  set("objects",([
     "/d/city/npc/bossdachang":1,
]));
  set("no_clean_up", 1);
  set("no_fight",1);
  set("no_magic",1);
  setup();
  expire();
}

int clean_up(){return 0;}

void init() {
   add_action("do_cun","jicun");
   add_action("do_qu","qu");
   add_action("do_pick","pick");
}

int do_cun(string arg) {
  int howlong,fees,afford;
  string boxname,mark;
  object box,me=this_player();

  if (!arg) 
    return notify_fail("��ʽ��jicun <��Ʒ> for <ʱ��>\n"+
            "ʱ����СʱΪ��λ����಻������ʮ��Сʱ��\n");

  if (sscanf(arg,"%s for %d",boxname,howlong)!=2)
    return notify_fail("��ʽ��jicun <��Ʒ> for <ʱ��>\n"+
            "ʱ����СʱΪ��λ����಻������ʮ��Сʱ��\n");
  box=present(boxname,me);
  if (!box) return notify_fail("�����ʲô��\n");

  if (howlong<1 || howlong>24) 
     return notify_fail("���ʱ��һ����ʮ��Сʱ��\n");
  if (box->query("id")!="deposit box")
     return notify_fail("Ϊ����������뽫�Ĵ���Ʒ�ȷ��������С�\n");

  if (!mark=box->query("mark")) 
     return notify_fail("�����������������Ǻ�(mark)��\n");

  if( !(afford=me->can_afford(howlong*100)) )  {
     write("��û���㹻��Ǯ��\n");
     return 1; 
  } else if( afford == 2 )  {
      write("��û���㹻����Ǯ������Ʊ��û���ҵÿ���\n");
      return 1;
  }
  if (box->move(findbox())) {
    box->set("owner",me->query("id"));
    box->set("expire_time",time()+howlong*3600);
    me->pay_money(howlong*100);
    message_vision("$N�Ĵ�����һֻ������"+chinese_number(howlong)+
               "Сʱ��\n",me);
    write("�涨�����ڣ����á�qu "+mark+"������ȡ����\n");
    return 1;
  } else 
    write("�Բ��𣬱����Ѿ����������´ι��١�\n");
  return 1;
}

int do_qu(string arg) {
  string mark;
  object *inv;
  object me=this_player();

  if (!arg) return notify_fail("��ʽ��qu <�Ǻ�>\n");
  inv=all_inventory(findbox());

  for (int i=0;i<sizeof(inv);i++) 
    if (inv[i]->query("owner")==me->query("id") &&
        inv[i]->query("mark")==arg ) {
          inv[i]->delete("owner");
          inv[i]->delete("expire_time");
          message_vision("$Nȡ��һֻ���С�\n",me);
          if (!inv[i]->move(me)) inv[i]->move(environment(me));
          return 1;
     }
  write("��û�д���Ǻ�Ϊ��"+mark+"���ĺ��ӣ������Ѿ������ˡ�\n");
  return 1;
}

void expire() {
  int time=time();
  object *inv;

  remove_call_out("expire");
  call_out("expire",900);

  inv=all_inventory(findbox());
  for (int i=0;i<sizeof(inv);i++)
    if (inv[i]->query("expire_time")<time) {
       inv[i]->delete("owner");
       inv[i]->delete("expire_time");
       inv[i]->move(findcart());
    }
}

int do_pick(string arg) {
  object *inv=all_inventory(findcart());
  object me=this_player();
  object pick;
  int afford;

  if (arg!="box") 
     return notify_fail("��ʽ��pick box\n�㽫�ڻ��������ѡ��һ�����С�\n");

  if (!inv || sizeof(inv)==0) 
     return notify_fail("����û��û�ջ�����ۡ�\n");                     

  if( !(afford=me->can_afford(1000)) )  {
     write("��û���㹻��Ǯ��\n");
     return 1; 
  } else if( afford == 2 )  {
      write("��û���㹻����Ǯ������Ʊ��û���ҵÿ���\n");
      return 1;
  }
    
  pick=inv[random(sizeof(inv))];
  me->pay_money(1000);
  pick->delete("owner");
  message_vision("$N����һ�����С�\n",me);
  if (!pick->move(me)) pick->move(environment(me));  
  return 1;
}

object findcart()
{
    if(cart && environment(cart)==this_object()) 
      return cart;

    cart=new("/std/room/shopbox");
    cart->move(this_object());
    cart->set("name","����");
    cart->set("short","����");
    return cart;
}

