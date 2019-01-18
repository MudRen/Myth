#include <ansi.h>
inherit ROOM;
mapping *rumors=allocate(10);
int index=0;
void create ()
{
  set ("short", "ҥ�Կ�������");
  set ("long",@LONG

һ�䲻��ķ��䣬�����޴���������һ����͵ĵƹ��£�
��ȴ�Ҳ�����Դ��������ܿ�ǽ�����˸�ɫ������������
���������̵�ָʾ�Ʋ�ͣ�������š�����ǽ�����Ÿ���
��----��Ҫ�˲�֪�����Ǽ�ĪΪ�������ǣ������ֻ֡�

LONG);
  set("no_clean_up", 1);
  CHANNEL_D->register_relay_channel("rumor");
  set("exits",([]));
  setup();
}

void relay_channel(object ob, string channel, string msg) {
   mapping rumor=allocate_mapping(4);
   if (channel!="rumor") return;
   rumor["disclose"]=0;
   if(userp(ob)) {
      rumor["name"]=ob->query("name");
      rumor["id"]=ob->query("id");
      if (!random(4)) 
        rumor["disclose"]=1;
   } 
   rumor["body"]=msg;
   if (wizardp(ob) && !ob->query("env/rumor_disclose")) 
        rumor["disclose"]=0;
   rumors[index]=rumor;
   index=(index+1)%10;   
   set("rumor",rumor);
}

void init() {
    if (!wizardp(this_player()))
      this_player()->move("/d/city/center");
  else {
   add_action("do_list","list");
   add_action("do_open","open");
  add_action("do_close","close");
  }
}

int do_list() {
  int i;
  mapping r;  
  for (i=1;i<=10;i++) {
    r=rumors[(index-i+10)%10];
    if (r) {
      write(r["name"]+"("+r["id"]+") says "+r["body"]);
      if (r["disclose"]) write(" [DISCLOSED]\n");
        else write("\n");
    }
  }
  return 1;
}
mapping reveal(int i) {
  return rumors[(index-i+10)%10];
}            
int clean_up() {return 0;}
int do_open(string arg) {
  int number,i;
  if (!arg || sscanf(arg,"%d",number)!=1) return notify_fail("wrong syntax.\n");
  i=(index-number+10)%10;
  if (!rumors[i]) return notify_fail("no such number.\n");
  rumors[i]["disclose"]=1;
  write("OK.\n");
  return 1;
}
int do_close(string arg) {
  int number,i;
  if (!arg || sscanf(arg,"%d",number)!=1) return notify_fail("wrong syntax.\n");
  i=(index-number+10)%10;
  if (!rumors[i]) return notify_fail("no such number.\n");
  rumors[i]["disclose"]=0;
  write("OK.\n");
}
