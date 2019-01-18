// Room: /d/qujing/wudidong/punish
inherit ROOM;

void create ()
{
  set ("short", "�ڰ���");
  set ("long", @LONG

������һƬ�ڰ������ֲ�����ָ���Ĵ��������غ�����Ϣ��Խ���Ե�
��ɭ�ֲ���ͻȻ��һ����紵��������һ���˱ǵ�ù���������ģ���
�е����������������������ﲢ��͸�硣
LONG);
  setup();
}
void init()
{
    object me=this_player();

    if(me->query("startroom")!="/d/qujing/wudidong/punish")
	me->set("startroom_old", me->query("startroom"));
    me->set("startroom", "/d/qujing/wudidong/punish");
    add_action("do_search", "search");
    add_action("do_search", "jiancha");
    add_action("do_dig", "dig");
    add_action("do_dig", "wa");
}
int do_search(string arg)
{
    object me=this_player();
    if (arg) return notify_fail("����û�� "+arg+"��\n");
    if (me->query("kee")*100/me->query("max_kee")< 30
     || me->query("sen")*100/me->query("max_sen")< 30)
        return notify_fail("���������ˣ���������ʵʵ�����Űɣ�\n");
    me->start_busy(random(40-me->query_kar()));
    tell_object(me, "�����ҿ��˿������˼��£��������ߵĳ�����Щ�ɶ���\n");
    me->set_temp("mark/wudidong_know_about_punishroom", 1);
    return 1;
}
int do_dig(string arg)
{
    object me=this_player();

//    if (me->query_skill("tianmo", 1)<30)
//        return notify_fail("�㻹ûѧ���޵׶��Ŀ��ұ��죡\n");
    if (!me->query_temp("mark/wudidong_know_about_punishroom"))
        return notify_fail("��ʲô��\n");
    tell_object(me, "�����˫�֣���һ�����������䣡ֻ��˫�ֱ��һ����צ��\n");
    tell_object(me, "���趯��צ��˲ʱ�佫�ɶ��ĳ����ڿ��ˣ�\n");
    tell_object(me, "�������צһ���������˫�֣����ݲ��ȵشӶ������˳�ȥ��\n");
    message_vision("ֻ��һ������������$N�����ˣ�\n", me);
    me->move(__DIR__"gongshi");
    me->set("startroom", me->query("startroom_old"));
    me->delete_temp("mark/wudidong_know_about_punishroom");
    message("vision", "����ʯ��ͻȻ¶�����󶴣�"+me->name()+"���������˳�����\n", me);
    return 1;
}
