
#include <ansi.h>
inherit ROOM;

void create() {

  set("short","С����ˮ");
  set("long", @LONG

һ����ɫ�����Сʯ�ţ��Ŷ��Ͽ��š�̫��������׭���֡�
����С����ˮ���ˣ���ˮ��Ө͸������������λ�������̣�
�ɷ���ǣ�����ʫ���衣һƬ������������գ��㼸������
������ķ��ա�

LONG);

  setup();
}

void init() {
   object host=query("host");
   object old_room=query("old_room");
   string dir,dest;

   if (!old_room) return;
   if (!host || environment(host)!=this_object()) {
      dir=old_room->query("altered_dir");
      dest=old_room->query("old_room");

      old_room->set("exits/"+dir,dest);
      this_player()->move(dest,1);
      destruct(this_object());
    }
}
       
int is_clear() {
  object *inv=all_inventory();

  for (int i=0;i<sizeof(inv);i++)
    if (userp(inv[i])) return 0;
  return 1;
}   
  
void explode() {
  object *inv=all_inventory();
  object me=query("host");
  string msg=HIW"��ʱ��";
  int flag=0;

  message_vision(HIW"$N��һ�̫��ͼӦ�ֶ��𣬾�£������\n"NOR,me);
  for (int i=0;i<sizeof(inv);i++)
     if (inv[i]!=me) {
        flag=1;
        msg=msg+inv[i]->name()+"��";
        inv[i]->receive_wound("kee",inv[i]->query("max_kee")*2,me);
     }
  msg+="����촷ۣ�\n"NOR;
  if (flag) message_vision(msg,me);

  me->move(query("old_room"));
  destruct(this_object());

}
  

