// story:liandan ����

#include <ansi.h>

int give_gift();

private mixed *story = ({
        "����ͯ��ƴ����ɿ��ֻ������¯�еĻ�����������",
        "̫���Ͼ����������дʣ�����",
        "����ͯ����æ��¯��һ�����������ɵ��ڿն���",
        "̫���Ͼ������һ�������ɵ�Ȧ�¡�",
        "̫���Ͼ������ɵ����˰��죬̾������֪�����ɵ��ܲ��ܷ������á�",
        "̫���Ͼ�����磡������Ҫ��Ҫ��������ɵ���",
        "���æ������ҡͷ��ʦ�����Ҿ����˰ɡ�",
        "̫���Ͼ������£�",
        "���»�æ�����ң��ң����Ѿ��Դ�ҩ�ˣ�",
        "̫���Ͼ���̾һ�����������Ƕ���ȥ���������԰ɡ�",
        (: give_gift :),
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift()
{
        STORY_D->give_gift("/clone/gift/unknowdan", 1,
                           HIM "\n��ž����һ��һ���ɵ���������ǰ��\n\n" NOR);
        return 1;
}
