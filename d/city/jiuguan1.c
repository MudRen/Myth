#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "������¥");
  set ("long", @LONG

�����������Ƿ糾��ʿ�㼯֮��������¥���������������������ġ���
���������мӡ�С�����žƺ�������������֮�䡣��ȭ����֮����Ц������
߳�������һƬ��Ҳ�ֲ�����Щ�����Ұ��ա���Щ������ǿ�ˡ�������˵
���������߻��ӡ���Ϊ��Ӷʿ���ĺ�ȥ����
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"center",
  "up" :"/d/city/changan",
]));
  set("objects", ([ /* sizeof() == 2 */
// ����by seng@2005-1-20
//  __DIR__"npc/xiaoer" : 1,
]));
  set("no_fight", 1);
  set("no_magic", 1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));
  setup();
}

void init()
{
    add_action("do_zhaomu", "zhaomu");
    add_action("do_money", "yuexiang");
    add_action("do_muji", "muji");
}

int do_zhaomu(string args)
{
  object me=this_player();
if(!args || (args != "soilder"))
return notify_fail("����ֻ����ļ��ʿ���������Ĵ�ҿ���û����Ȥ��Ŷ��\n");
if(!me->query("office_number"))
return notify_fail("�㻹û�������ء�������ɶ���൱ǿ���췴���ɣ�\n");
if(me->query("soilder") >= (me->query("office_number")*10000))
return notify_fail("�����±�Ա�Ѿ����û�ж����ָ���ˡ�Ҫ����������ȥ������ҵ�ɣ�\n");
message_vision("�����һ�½��ƺ�˦�ڵ��ϡ����ҵ����������˴�Ҿ����Ŀ�⡣�������������
����˵������û���˸���ȥ����ѽ��\n",me);
tell_object(me,"�����������Ϊ��"+chinese_number(me->query("office_number"))+"���ˡ�Ŀǰȱ��:"+chinese_number(
me->query("office_number")*10000 - me->query("soilder"))+". \n");
tell_object(me,"������Ҫ�Խ�Ǯ��Ϊ��Ǯ�ġ�û�о��û��߾���̫�ͣ���û����Ը������ߵġ�\n
ļ����Ҫ�ȸ�һ��ľ��ã��Ժ�Ͳ����ٻ�Ǯ�ˡ���Ҫ����������ļ����(���һ������)\n");
tell_object(me,"������Ҫ�������á�\n");
me->set_temp("zhaomu_ing",1);
return 1;
}

int do_money(string arg)
{
 object me=this_player();
 int pts;
if(!me->query_temp("zhaomu_ing")) return notify_fail("����Ҫ�����ҵ�ע�����.\n");
if( !arg || !sscanf(arg, "%d", pts)) 
return notify_fail("ָ���ʽ��yuexiang <ÿ��ÿ��ʿ��������>\n");
if(me->query("balance")/(1200*pts) < 100) return notify_fail("��Ĵ��̫�٣�����ȥ�跨��׬��Ǯ�����ɣ�\n");
me->set("soilder_pay",pts);
tell_object(me,"����Ŀǰ�Ĳ���������ļ����"+me->query("balance")/(1200*pts)+"�ˡ�
ʵ��ȱ�"+chinese_number(me->query("office_number")*10000 - me->query("soilder"))+" ��Ҫļ��������?
����muji <����> ������.\n");
me->delete_temp("zhaomu_ing");
me->set_temp("give_pay",1);
me->set_temp("longer",me->query("balance")/(1200*pts));
return 1;
}

int do_muji(string arg)
{
object me=this_player();
int pts,train,longer1;
longer1=me->query_temp("longer");
if(!me->query_temp("give_pay")) return notify_fail("�㲻�����ʣ�˭����׸�ѽ��\n");
if( !arg || !sscanf(arg, "%d", pts)) 
return notify_fail("ָ���ʽ��muji <ʿ����>\n");
if(pts > (me->query("office_number")*10000 - me->query("soilder")) ) 
return notify_fail("�㲻��ļ�����������������������\n");
if(pts > longer1)
return notify_fail("�㲻��ļ���������������������!!\n");
if(pts < 0)
return notify_fail("��Ͷ��ѽ!ץ�ľ�����!\n");
message_vision("ֻ����ͷӿ������Щ��������֮ͽ�׷׹������������������һЩ����ȥ��׳֮�ˡ�\n",me);
tell_object(me,"��������"+chinese_number(pts)+"��ʿ����\n");
me->add("balance",-pts*1200);
train=me->query("train_level")*me->query("soilder")+10*pts;
me->add("soilder",pts);
train=train/(me->query("soilder"));
me->set("train_level",train);   //ʿ����ѵ���ȡ�
message("vision",HIY+"��ս��׷ɡ�:"+NOR+HIC+me->query("name")+"�ڱ�Ӫļ����"+chinese_number(pts)+
"��ʿ��.\n"+NOR,users());
me->delete_temp("give_pay");
me->delete_temp("longer");
return 1;
}


