// story:laojun

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "��ʴ�ۣ��Ͼ������Ƕ���û���α�����ҩ��",
        "̫���Ͼ����У��У��������������һ���ɵ�������ʹ�˱������",
        "��ʴ�۴�ϲ�����ã���������š�",
        "̫���Ͼ��ɻ����Ī��......",
        "��ʴ�۳�̾һ�������ǲ��ǣ����Ǽ��ǿ�����Խ��Խ�����ˣ�����԰�����ˣ������������¹��ء�",
        "̫���Ͼ��ͳ�һ��«�����������",
        "��ʴ�ۣ�" HIC "��ѽ��" NOR,
        "̫���Ͼ������ã���ô���ˣ���������ȥ���ҡ�",
        "��ʴ�ۣ��������ˣ�����һ�ɵ���ٸ���һ�ž����ˡ�",
        (: give_gift :)
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
        STORY_D->give_gift("/clone/gift/xiandan", 1,
                           HIM "\n��ž����һ��һö�ɵ���������ǰ��\n\n" NOR);
        return HIM "��˵��ͥ������һö�ɵ���\n" NOR;
}
